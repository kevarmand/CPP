/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:12:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 19:21:04 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int main() {


	std::cout << BOLDCYAN "\n--- Simulation Start ---\n" RESET << std::endl;
	std::cout << BOLDCYAN "ClapTrap  name : C3PO" RESET << std::endl;
	FragTrap claptrap("Daneel");

	std::cout << BOLDCYAN "TEST des attributs de base " RESET << std::endl;
	claptrap.attack("R2D2");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.highFivesGuys();
	claptrap.highFivesGuys();
	

	std::cout << std::endl << BOLDCYAN "TEST des limites de vie " RESET << std::endl;
	claptrap.takeDamage(200);
	claptrap.attack("target_2");
	claptrap.beRepaired(10);
	claptrap.takeDamage(10);
	claptrap.highFivesGuys();
	

	std::cout << BOLDCYAN "\n--- Simulation End ---\n" RESET << std::endl;

	return 0;
}