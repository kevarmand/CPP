/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:23:48 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 17:29:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>


ClapTrap::ClapTrap(const std::string& name)
: _name(name),
  _hitPoints(10),
  _energyPoints(10),
  _attackDamage(0) {
	std::cout << BOLDGREEN "ClapTrap " BLUE_SOFT << _name <<RESET GREEN " constructed." RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
: _name(other._name),
  _hitPoints(other._hitPoints),
  _energyPoints(other._energyPoints),
  _attackDamage(other._attackDamage) {

	std::cout << GREEN "ClapTrap " BOLD_BLUE_SOFT << _name << RESET GREEN " copy constructed." RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << GREEN "ClapTrap " BOLD_BLUE_SOFT << _name << RESET GREEN " assigned." RESET << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << BOLDRED "ClapTrap " BLUE_SOFT << _name << RESET RED " destroyed." RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "\U00002694  ";
	if (_energyPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BLUE_SOFT << _name << RESET " has no energy points left to attack." << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BLUE_SOFT << _name << RESET " has no hit points left and cannot attack." << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " attacks " << target
				<< ", causing " RED << _attackDamage << RESET " points of damage!"
				<< "\n\t(" YELLOW "Energy points left: " << _energyPoints << RESET ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "\U0001F4A5 ";
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " is already destroyed and cannot take more damage." << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0) _hitPoints = 0;
	std::cout << "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " takes " RED << amount
				<< RESET " points of damage!\n\t(" NGREEN "Hit points left: " << _hitPoints << RESET ")" << std::endl;
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " is destroyed.\U0001F622" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "\U0001F6E0  ";
	if (_hitPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " is destroyed and cannot be repaired." << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << ORANGE "[WARNING] : " RESET "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " has no energy points left to repair." << std::endl;
		return;
	}
	
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " BOLD_BLUE_SOFT << _name << RESET " repairs itself for " NGREEN << amount
				<< RESET " hit points!\n\t(" NGREEN "Hit points: " << _hitPoints
				<< RESET ", " YELLOW "Energy points left: " << _energyPoints << RESET ")" << std::endl;
}