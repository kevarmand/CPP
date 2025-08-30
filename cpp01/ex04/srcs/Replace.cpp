/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:56:42 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 17:32:32 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 

#include "Replace.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */

Replace::Replace(const std::string& filename,
		const std::string& s1,
		const std::string& s2)
		: _needle(s1),
		_replacement(s2)
{
	_inputFile.open(filename.c_str());
	_outputFile.open((filename + ".replace").c_str());
	_ok = true;

	if (filename.empty())
	{
		std::cerr << RED "Error: File empty !" RESET << std::endl;
		_ok = false;
		return ;
	}
	if (s1.empty())
	{
		std::cerr << RED "Error: s1 empty !" RESET << std::endl;
		_ok = false;
		return ;
	}
	if (!_inputFile.is_open())
	{
		std::cerr << RED "Error: Cannot opening file !" RESET << std::endl;
		_ok = false;
		return ;
	}
	if (!_outputFile.is_open())
	{
		std::cerr << RED "Error: Cannot create file !" RESET << std::endl;
		_inputFile.close();
		_ok = false;
		return ;
	}
}

Replace::~Replace()
{
	_inputFile.close();
	_outputFile.close();
}


static bool read_chunk(std::istream& in, char* line, std::size_t cap, std::size_t& size) {
	in.read(line, static_cast<std::streamsize>(cap));
	if (in.bad()) {
		std::cerr << RED "Error: Read failure on input file" RESET << std::endl;
		size = 0;
		return false;
	}
	std::streamsize n = in.gcount();
	size = static_cast<std::size_t>(n);
	line[size] = '\0';
	return true;
}

static bool write_stream(std::ostream& out, const std::string& str) {
	out << str;
	if (out.bad()) {
		std::cerr << RED "Error: Write failure on output file" RESET << std::endl;
		return false;
	}
	return true;
}


bool	Replace::run()
{
	if (!_ok)
		return false;
	char	buffer[BUFFER_SIZE + 1];
	
	// First case : if needle == replacement, just copy input to output
	if (_needle == _replacement) {
		char buf[BUFFER_SIZE];
		std::size_t got = BUFFER_SIZE;
		while (read_chunk(_inputFile, buf, BUFFER_SIZE, got) && got > 0) {
			_outputFile.write(buf, static_cast<std::streamsize>(got));
			if (!_outputFile.good()) { std::cerr << RED "Error: write failure" RESET << std::endl; return false; }
		}
		return _inputFile.eof() && _outputFile.good();
	}
	
	
	// Normal case: needle != replacement
	std::size_t size = BUFFER_SIZE;
	if (!read_chunk(_inputFile, buffer, BUFFER_SIZE, size))
		return false;
	buffer[size] = '\0';
	while (1)
	{
		//find and replace in buffer using std::string
		
		std::string str(buffer);
		std::size_t pos = 0;
		while ((pos = str.find(_needle, pos)) != std::string::npos)
		{
			if (!write_stream(_outputFile, str.substr(0, pos))
				|| !write_stream(_outputFile, _replacement))
				return false;
			str = str.substr(pos + _needle.size());
			pos = 0;
		}
		
		// 0) find , fail so no match in buffer

		// In this case we have all the data in str
		if (size != BUFFER_SIZE)
		{
			if (!write_stream(_outputFile, str))
				return false;
			break ;
		}
		
		// We need to keep a suffix of str to handle the case where
		std::size_t suffix_len = _needle.size() - 1;
		if (str.size() > suffix_len) {
			if (!write_stream(_outputFile, str.substr(0, str.size() - suffix_len)))
				return false;
			str = str.substr(str.size() - suffix_len);
		}
		else
		{
			suffix_len = str.size();
		}
		std::size_t cap = BUFFER_SIZE - suffix_len;
		std::memcpy(buffer, str.data(), suffix_len); // recopie le suffixe au début
		if (!read_chunk(_inputFile, buffer + suffix_len, cap, size))
			return false;

		// sinon, on a lu "size" octets après le suffixe → maj de size totale
		size += suffix_len;
		buffer[size] = '\0';
	}
	return _inputFile.eof() && _outputFile.good();
}
