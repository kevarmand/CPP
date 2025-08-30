/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:02:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:36:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << E_CURE
			<< GREEN BOLD "[" UNDERLINE GREEN "Cure" NO_UNDERLINE 
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << E_CURE
			<< YELLOW BOLD "[" UNDERLINE GREEN "Cure" WHITE NO_UNDERLINE 
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << E_CURE
			<< YELLOW BOLD "[" UNDERLINE GREEN "Cure" NO_UNDERLINE 
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	std::cout << E_CURE
			<< RED BOLD "[" UNDERLINE GREEN "Cure" NO_UNDERLINE 
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}


void Cure::use(ICharacter& target) {
	std::cout << E_CURE
	<< "*"  BOLD GREEN " heals " RESET << target.getName() << "'s wounds *" << std::endl;
}

