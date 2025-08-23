/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:33:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 20:43:18 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplacerAlgorithm.hpp"
#include "FileReplacer.hpp"

#include <iostream>
#include <fstream>

FileReplacer::FileReplacer(const std::string& in,
						const std::string& out,
						const std::string& s1,
						const std::string& s2)
: _in(in), _out(out), _s1(s1), _s2(s2) {}

int FileReplacer::run() {
	if (_in.empty()) {
		std::cerr << "Error: filename must not be empty\n";
		return 1;
	}
	if (_s1.empty()) {
		std::cerr << "Error: s1 must not be empty (would cause infinite replacements)\n";
		return 1;
	}

	std::ifstream ifs(_in.c_str(), std::ios::in | std::ios::binary);
	if (!ifs) {
		std::cerr << "Error: cannot open input file: " << _in << "\n";
		return 1;
	}

	std::ofstream ofs(_out.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (!ofs) {
		std::cerr << "Error: cannot open output file: " << _out << "\n";
		return 1;
	}

	// Fast-path: s1 == s2 => simple copie
	if (_s1 == _s2) {
		stream_copy(ifs, ofs);
		if (!ofs.good()) {
			std::cerr << "Error: write failure on output file\n";
			return 1;
		}
		return 0;
	}

	ReplacerAlgorithm algo(_s1, _s2);

	enum { BLOCK = 64 * 1024 }; // 64 KiB
	char buf[BLOCK];
	std::string window;
	window.reserve(BLOCK + _s1.size());

	while (ifs) {
		ifs.read(buf, BLOCK);
		std::streamsize got = ifs.gcount();
		if (got > 0) {
			window.append(buf, static_cast<std::size_t>(got));
			const std::size_t keep = _s1.size() > 0 ? _s1.size() - 1 : 0;
			algo.process(window, ofs, keep);
			if (!ofs.good()) {
				std::cerr << "Error: write failure on output file\n";
				return 1;
			}
		}
	}

	if (!ifs.good() && !ifs.eof()) {
		std::cerr << "Error: read failure on input file\n";
		return 1;
	}

	// Vidage final
	algo.flush(window, ofs);

	if (!ofs.good()) {
		std::cerr << "Error: write failure on output file\n";
		return 1;
	}

	return 0;
}

void FileReplacer::stream_copy(std::istream& in, std::ostream& out) {
	enum { BLOCK = 64 * 1024 };
	char buf[BLOCK];
	while (in) {
		in.read(buf, BLOCK);
		std::streamsize got = in.gcount();
		if (got > 0)
			out.write(buf, got);
	}
}
