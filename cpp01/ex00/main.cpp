/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 14:53:33 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

# define CYAN			"\033[36m"				/* Cyan */
# define GREY			"\033[90m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */



Zombie *in_scope( void ) {
	
	std::cout << CYAN<< "Entering new scope" RESET << std::endl << std::endl;

	//z3 (HEAP)
	std::cout << CYAN<< "Creating 1 Zombie in scope ( heap )" RESET;
	std::cout << GREY << " [Zombie* z3 = newZombie(\"Fergal_Lawler\");]" RESET << std::endl;
	Zombie* z3 = newZombie("Fergal_Lawler");
	std::cout << std::endl;

	//z4 (STACK)
	std::cout << CYAN<< "Creating 1 Zombie in scope ( stack )" RESET ;
	std::cout << GREY << " [Zombie z4(\"Niall_Quinn\");]" RESET << std::endl;
	Zombie z4("Niall_Quinn");
	std::cout << std::endl;

	std::cout << CYAN << "make them announce" RESET << std::endl;
	std::cout << GREY << "z3->announce();" RESET << std::endl;
	z3->announce();
	std::cout << GREY << "z4.announce();" RESET << std::endl;
	z4.announce();
	std::cout << std::endl;
	std::cout << CYAN<< "Leaving scope" RESET << std::endl << std::endl;
	return (z3);
}

int main() {
	
	//Zombie* z1;
	std::cout << CYAN<< "Creating 1 Zombies in main ( stack )" RESET ;
	std::cout << GREY << " [Zombie z1(\"Dolores_O_Riordan\");]" RESET << std::endl;
	Zombie z1("Dolores_O_Riordan");
	std::cout << CYAN << "make it announce" RESET;
	std::cout << GREY << " [z1.announce();]" RESET << std::endl;
	z1.announce();
	std::cout << std::endl;

	//Zombie* z2; (HEAP)
	std::cout << CYAN<< "Creating 1 Zombie in main ( heap )" ;
	std::cout << GREY << " [Zombie* z2 = newZombie(\"Noel_Hogan\");]" RESET << std::endl;
	Zombie* z2 = newZombie("Noel_Hogan");
	std::cout << CYAN << "make it announce" RESET ;
	std::cout << GREY << " [z2->announce();]" RESET << std::endl;
	z2->announce();
	std::cout << std::endl;

	//randomChump
	std::cout << CYAN<< "Creating 1 Zombie in randomChump ( stack )" RESET ;
	std::cout << GREY << " [randomChump(\"Mike_Hogan\");]" RESET << std::endl;
	randomChump("Mike_Hogan");
	std::cout << std::endl;
	
	std::cout << CYAN<< "Create a new scope" RESET << std::endl;
	
	Zombie* z3 = in_scope();

	std::cout << CYAN << "Back in main" RESET << std::endl << std::endl;

	std::cout << CYAN<< "Deleting Heap Zombies" RESET << std::endl;
	std::cout << GREY << "[delete z2;]" RESET << std::endl;
	delete z2;
	std::cout << GREY << "[delete z3;]" RESET << std::endl;
	delete z3;
	std::cout << std::endl;

	std::cout << CYAN << "No need to delete Stack Zombies" GREY "return 0;" RESET << std::endl;
	return (0);
}