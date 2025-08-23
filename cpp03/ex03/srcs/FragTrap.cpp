/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:05:59 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 20:08:31 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name) {
	_hitPoints = defaultHitPoints;
	_energyPoints = defaultEnergyPoints;
	_attackDamage = defaultAttackDamage;
	std::cout << BOLDGREEN "FragTrap" NO_BOLD << " named " BOLD BLUE_STD << name << RESET GREEN " landed from the sky!" RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) 
: ClapTrap(other) {
	std::cout << BOLDGREEN "FragTrap" NO_BOLD << " copy constructed!" RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << BOLDRED "FragTrap" NO_BOLD << " named " BOLD BLUE_STD << _name << NO_BOLD << RESET RED " has flown away!" RESET << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "\U0001F91D ";
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "FragTrap " BOLD BLUE_STD << _name << RESET " has no hit points left and cannot request high fives." << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "FragTrap " BOLD BLUE_STD << _name << RESET " has no energy points left to request high fives." << std::endl;
		return;
	}

	std::cout << "FragTrap " BOLD BLUE_STD << _name << RESET " is requesting high fives! \U0001F91D" << std::endl;
}