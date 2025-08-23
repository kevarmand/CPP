/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 20:37:42 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FileReplacer.hpp"


int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << (argc > 0 ? argv[0] : "replace")
				<< " <filename> <s1> <s2>\n";
		return 1;
	}

	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	const std::string outname = filename + ".replace";

	FileReplacer job(filename, outname, s1, s2);
	return job.run();
}
