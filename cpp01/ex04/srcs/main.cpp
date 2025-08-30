/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 16:44:58 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Replace.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */

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

	Replace job(filename, s1, s2);
	if (job.run()) {
		std::cout << GREEN "Replacement saved to file: " RESET << outname << std::endl;
	} else {
		std::cerr << RED "Error: Replacement failed" RESET << std::endl;
	}
	return 0;
}
