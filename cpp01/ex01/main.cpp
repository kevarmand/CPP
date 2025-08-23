/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 15:37:12 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

# define CYAN			"\033[36m"				/* Cyan */
# define GREY			"\033[90m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */



int main() {
	
	//Creation d une horde de 14 Zombies
	std::cout << CYAN<< "Creating a horde of 14 Zombies ( heap )" ;
	std::cout << GREY << " [Zombie* horde = zombieHorde(14, \"Oscar\");]" RESET << std::endl;
	Zombie* horde = zombieHorde(14, "Oscar");
	std::cout << CYAN << "make them announce" RESET ;
	std::cout << GREY << std::endl << " [for (int i = 0; i < 14; ++i) \n\t std::cout << i << \" :\"; \n\t horde[i].announce();]" RESET << std::endl;
	for (int i = 0; i < 14; ++i) {
		std::cout << GREY  << i << " :" RESET;
		horde[i].announce();
	}
	
	std::cout << CYAN << "Deleting the horde" ;
	std::cout << GREY << " [delete[] horde;]" RESET << std::endl;
	delete[] horde;
	return 0;
}