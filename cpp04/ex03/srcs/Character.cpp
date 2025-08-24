/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:57:53 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 18:12:52 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = 0;
	}
	// std::cout << GREEN << "Character " << name << " constructed." << RESET << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	// std::cout << GREEN << "Character copy constructor called." << RESET << std::endl;
}

Character& Character::operator=(const Character& other) {
	// std::cout << GREEN << "Character assignment operator called." << RESET << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; ++i) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
			if (other._inventory[i]) {
				_inventory[i] =	 other._inventory[i]->clone();
			} else {
				_inventory[i] = 0;
			}
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
	// std::cout << RED << "Character " << name << " destructed." << RESET << std::endl;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << YELLOW << "Cannot equip a null materia." << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			// std::cout << GREEN << name << " equipped " << m->getType() << " in slot " << i << "." << RESET << std::endl;
			return;
		}
	}
	std::cout << YELLOW << _name << "'s _inventory is full. Cannot equip " << m->getType() << "." << RESET << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << YELLOW << "Invalid _inventory index: " << idx << "." << RESET << std::endl;
		return;
	}
	if (_inventory[idx]) {
		// std::cout << GREEN << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << "." << RESET << std::endl;
		_inventory[idx] = 0;
	} else {
		std::cout << YELLOW << "No materia to unequip in slot " << idx << "." << RESET << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << YELLOW << "Invalid _inventory index: " << idx << "." << RESET << std::endl;
		return;
	}
	if (_inventory[idx]) {
		_inventory[idx]->use(target);
	} else {
		std::cout << YELLOW << "No materia to use in slot " << idx << "." << RESET << std::endl;
	}
}

