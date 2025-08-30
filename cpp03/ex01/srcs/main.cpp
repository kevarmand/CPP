/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:12:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 15:05:55 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int main() {


	std::cout << BOLDCYAN "\n--- Simulation Start ---\n" RESET << std::endl;
	std::cout << BOLDCYAN "ClapTrap  name : C3PO" RESET << std::endl;
	ScavTrap claptrap("C3PO");

	std::cout << BOLDCYAN "TEST des attributs de base " RESET << std::endl;
	claptrap.attack("R2D2");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.guardGate();
	

	std::cout << std::endl << BOLDCYAN "\nTEST une fois en Guard Mode " RESET << std::endl;
	claptrap.attack("R2D2");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	claptrap.guardGate();

	std::cout << std::endl << BOLDCYAN "TEST blulage d'energie " RESET << std::endl;
	for (int i = 0; i < 6; i++)
		claptrap.guardGate();
	for (int i = 0; i < 7; i++)
		claptrap.attack("R2D2");

	std::cout << std::endl << BOLDCYAN "TEST des limites d'energie " RESET << std::endl;
	claptrap.beRepaired(5);
	claptrap.attack("target_final");
	claptrap.takeDamage(15);
	claptrap.guardGate();
	claptrap.takeDamage(15);
	

	std::cout << std::endl << BOLDCYAN "TEST des limites de vie " RESET << std::endl;
	claptrap.takeDamage(200);
	claptrap.attack("target_2");
	claptrap.beRepaired(10);
	claptrap.takeDamage(10);
	

	std::cout << BOLDCYAN "\n--- Simulation End ---\n" RESET << std::endl;

	// petit test valgrind
	ClapTrap *p = new ScavTrap("Daneel");
	delete p;
	return 0;
}