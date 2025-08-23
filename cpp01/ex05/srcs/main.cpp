/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 21:48:03 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>


#include "Harl.hpp"

# define CYAN			"\033[36m"				/* Cyan */
# define RESET			"\033[0m"				/* Reset color */



int main() {
	
	Harl harl;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};


	for (int i = 0; i < 5; i++) {
		harl.complain(levels[i]);
	}
	for (int i = 5; i >= 0; i--) {
		harl.complain(levels[i]);
	}

	return 0;
}