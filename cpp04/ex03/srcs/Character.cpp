/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:57:53 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:37:56 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>


static const char* get_color(const std::string& type) {
	if (type == "ice")
		return BLUE_SOFT;
	else if (type == "cure")
		return GREEN;
	else if (type == "fire")
		return FIRE_CLR;
	else if (type == "earth")
		return BROWN;
	else if (type == "lightning")
		return YELLOW;
	else if (type == "chaos")
		return MAGENTA;
	return RESET;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = 0;
	}
	std::cout << E_CHAR
			<< GREEN BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
			<< _name
			<< GREEN BOLD "]" NO_BOLD
			<< " has entered the realm." << RESET << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	std::cout << E_CHAR
			<< YELLOW BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
			<< _name
			<< YELLOW BOLD "]" NO_BOLD
			<< " copy constructed." << RESET << std::endl;
}

Character& Character::operator=(const Character& other) {
	std::cout << E_CHAR
			<< GREEN BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
			<< _name
			<< GREEN BOLD "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
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
	std::cout << E_CHAR
			<< RED BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
			<< _name
			<< RED BOLD "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << E_CHAR
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Cannot equip null materia." 
			<< RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << E_CHAR
					<< BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
					<< _name
					<< BOLD "]" NO_BOLD
					<< " equipped " << get_color(m->getType()) << m->getType() << RESET
					<< " in slot " << i << "." << RESET << std::endl;
			return;
		}
	}
	std::cout << E_CHAR
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Cannot equip more materia, inventory full." 
			<< RESET << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << E_CHAR
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Invalid inventory index: " << idx << "." 
			<< RESET << std::endl;
		return;
	}
	if (_inventory[idx]) {
		std::cout << E_CHAR
			<< BOLD "[" UNDERLINE "Character" NO_UNDERLINE " : "
			<< _name
			<< BOLD "]" NO_BOLD
			<< " unequipped " << get_color(_inventory[idx]->getType()) << _inventory[idx]->getType() << RESET
			<< " from slot " << idx << "." << RESET << std::endl;
		_inventory[idx] = 0;
	} else {
		std::cout << E_CHAR
			<< YELLOW BOLD "[WARNING]" RESET
			<< " No materia to unequip in slot " << idx << "." << RESET << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << E_CHAR
			<< YELLOW BOLD "[WARNING]" RESET
			<< " Invalid inventory index: " << idx << "." << RESET << std::endl;
		return;
	}
	if (_inventory[idx]) {
		_inventory[idx]->use(target);
	} else {
		std::cout << E_CHAR
			<< YELLOW BOLD "[WARNING]" RESET
			<< " No materia equipped in slot " << idx << "." << RESET << std::endl;
	}
}

