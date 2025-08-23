/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:32:34 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 20:32:48 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_REPLACER_HPP
#define FILE_REPLACER_HPP

#include <string>

class FileReplacer {
public:
	FileReplacer(const std::string& in,
				const std::string& out,
				const std::string& s1,
				const std::string& s2);

	int run();

private:
	static void stream_copy(std::istream& in, std::ostream& out);

private:
	std::string _in, _out, _s1, _s2;
};

#endif // FILE_REPLACER_HPP
