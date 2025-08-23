/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:12:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 14:56:47 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


int main() {

	// on ecrit ce qu on fait en BOLDCYAN
	std::cout << BOLDCYAN "\n--- Simulation Start ---\n" RESET << std::endl;
	std::cout << BOLDCYAN "ClapTrap  name : C3PO" RESET << std::endl;
	ClapTrap claptrap("C3PO");

	std::cout << BOLDCYAN "TEST des attribu de base " RESET << std::endl;
	claptrap.attack("target_1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	std::cout << std::endl << BOLDCYAN "\nTEST des limites " RESET << std::endl;
	for (int i = 0; i < 10; ++i) {
		claptrap.attack("RD2D2");
	}
	std::cout << std::endl << BOLDCYAN "TEST des limites d'energie " RESET << std::endl;
	claptrap.beRepaired(5);
	claptrap.attack("target_final");
	claptrap.takeDamage(15);

	std::cout << std::endl << BOLDCYAN "TEST des limites de vie " RESET << std::endl;
	claptrap.takeDamage(8);
	claptrap.attack("target_2");
	claptrap.beRepaired(10);
	claptrap.takeDamage(10);
	return 0;
}