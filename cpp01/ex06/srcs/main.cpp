/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 21:48:22 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "Harl.hpp"

# define CYAN			"\033[36m"				/* Cyan */
# define RESET			"\033[0m"				/* Reset color */


static int level_index(const std::string& s, const std::string levels[4]) {
	
	for (int i = 0; i < 4; ++i)
		if (s == levels[i]) return i;
	return -1;
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>\n";
		return 1;
	}

	static std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	Harl h;
	switch (level_index(av[1], levels)) {
		case 0: h.complain(levels[0]);
		case 1: h.complain(levels[1]);
		case 2: h.complain(levels[2]);
		case 3: h.complain(levels[3]);
		break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return 0;
}