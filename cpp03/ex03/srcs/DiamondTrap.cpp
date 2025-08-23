/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:33:57 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 20:15:42 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"),
  ScavTrap(name),
  FragTrap(name),
  _name(name) {
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << BOLDGREEN "DiamondTrap " BROWN << _name << RESET GREEN " constructed." RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  _name(other._name) {
	std::cout << BOLDGREEN "DiamondTrap " BROWN << _name << RESET GREEN " copy constructed." RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << BOLDGREEN "DiamondTrap " BROWN << _name << RESET GREEN " assigned." RESET << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << BOLDRED "DiamondTrap " BROWN << _name << RESET RED " destructed." RESET << std::endl;
}

void DiamondTrap::whoAmI() const {
	std::cout
		<< "\u2753  "
		<< "You dare ask me who I am? "
		<< "Behold! I am " BOLD BROWN << _name << RESET
		<< ", proud descendant of " BOLDBLUE "Scav" RESET " and " BOLD BLUE_STD "Frag" RESET
		<< ". In the ancient registries they call me "
		<< BOLD_BLUE_SOFT << ClapTrap::_name << RESET
		<< ", but my friends simply say " BOLD BROWN << _name << RESET
		<< ". \u2728"  // ✨ (monochrome-friendly)
		<< std::endl;
}