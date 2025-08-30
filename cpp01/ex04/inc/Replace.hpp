/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:06:59 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 17:37:14 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>


class Replace {
public:
	Replace(const std::string& filename,
		const std::string& needle, const std::string& replacement);
	~Replace();
	
	bool	run();

private:
	static const int	BUFFER_SIZE = 65536; // 64KB

	const std::string		_needle;
	const std::string		_replacement;
	std::ifstream	_inputFile;
	std::ofstream	_outputFile;
	bool 			_ok;

};

#endif // REPLACE_HPP