/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:16:40 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 17:48:05 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name)
:	ClapTrap(name), _guardMode(false)
 {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << BOLDGREEN "ScavTrap" NO_BOLD << " named " BOLDBLUE << name << RESET GREEN " emerges from the shadows!" RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
	_guardMode = other._guardMode;
	std::cout << BOLDGREEN "ScavTrap" NO_BOLD << " copy constructed!" RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardMode = other._guardMode;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << BOLDRED "ScavTrap" NO_BOLD << " named " BOLDBLUE << _name << NO_BOLD << RESET RED " has been destroyed!" RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "\U00002694  ";
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ScavTrap " BOLDBLUE << _name << RESET " has no hit points left and cannot attack." << std::endl;
		return;
	}
	if (_guardMode) {
		std::cout << ORANGE "[WARNING] : " RESET "ScavTrap " BOLDBLUE << _name << RESET " is in Guard Mode and cannot attack." << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ScavTrap " BOLDBLUE << _name << RESET " has no energy points left to attack." << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << "ScavTrap " BOLDBLUE << _name << RESET " dashes in and strikes " << target
			  << ", dealing " RED << _attackDamage << RESET << " damage! It's super effective!" << std::endl;
	std::cout << "\t(" YELLOW "Energy points left: " << _energyPoints << RESET ")" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "\U0001F6E1  ";
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ScavTrap " BOLDBLUE << _name << RESET " has no hit points left and cannot enter in " MAGENTA "Guard Mode" RESET "."<< std::endl;
		return;
	}

	
	if (!_guardMode) {
		if (_energyPoints < 10) {
			std::cout << ORANGE "[WARNING] : " RESET "ScavTrap " BOLDBLUE << _name << RESET " doesn't have enough energy points left to enter " MAGENTA "Guard Mode" RESET "." << std::endl;
			return;
		}
		_energyPoints -= 10;
		std::cout << "ScavTrap " BOLDBLUE << _name << RESET " has entered " MAGENTA "Guard Mode" RESET ". It is now on high alert!" RESET << std::endl;
		std::cout << "\t(" YELLOW "Energy points left: " << _energyPoints << RESET ")" << std::endl;
	} else {
		std::cout << "ScavTrap " BOLDBLUE << _name << RESET " has exited " MAGENTA "Guard Mode" RESET ". It is now relaxed." RESET << std::endl;
	}
	_guardMode = !_guardMode;
}