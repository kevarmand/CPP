/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:54:27 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:37:44 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
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

AMateria::AMateria(const std::string& type) : type(type) {
	std::cout << E_MA
			<< GREEN BOLD "[" UNDERLINE "AMateria" NO_UNDERLINE " : "
			<< get_color(type) << type << RESET
			<< GREEN BOLD "]" NO_BOLD
			<< " core bound." << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << E_MA
			<< YELLOW BOLD "[" UNDERLINE "AMateria" NO_UNDERLINE " : "
			<< get_color(type) << type << RESET
			<< YELLOW BOLD "]" NO_BOLD
			<< " copy constructed." << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << E_MA
			<< YELLOW BOLD "[" UNDERLINE "AMateria" NO_UNDERLINE " : "
			<< get_color(type) << type << RESET
			<< YELLOW BOLD "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		// 'type' is const, so we don't assign it
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << E_MA
			<< RED BOLD "[" UNDERLINE "AMateria" NO_UNDERLINE " : "
			<< get_color(type) << type << RESET
			<< RED BOLD "]" NO_BOLD
			<< " core unbound." << RESET << std::endl;
}

const std::string& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}
