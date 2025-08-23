/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplacerAlgorithm.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:30:20 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 20:39:20 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplacerAlgorithm.hpp"
#include <ostream>  // std::ostream

ReplacerAlgorithm::ReplacerAlgorithm(const std::string& s1, const std::string& s2)
: _s1(s1), _s2(s2) {}

void ReplacerAlgorithm::process(std::string& window, std::ostream& out, std::size_t keep_suffix) {
	if (_s1.empty()) {
		if (!window.empty())
			out.write(window.c_str(), (std::streamsize)window.size());
		window.clear();
		return;
	}

	if (keep_suffix > window.size())
		keep_suffix = window.size();

	const std::size_t limit = window.size() - keep_suffix; // zone sûre à vider
	std::size_t pos = 0;

	while (true) {
		std::size_t found = window.find(_s1, pos);
		if (found == std::string::npos || found >= limit) {
			if (limit > pos)
				out.write(window.c_str() + pos, (std::streamsize)(limit - pos));
			break;
		}
		if (found > pos)
			out.write(window.c_str() + pos, (std::streamsize)(found - pos));
		if (!_s2.empty())
			out.write(_s2.c_str(), (std::streamsize)_s2.size());
		pos = found + _s1.size();
	}

	
	std::string tail;
	if (keep_suffix > 0)
		tail.assign(window, limit, keep_suffix);
	else
		tail.clear();

	window.swap(tail);
}

void ReplacerAlgorithm::flush(std::string& window, std::ostream& out) {
	process(window, out, 0);
}
