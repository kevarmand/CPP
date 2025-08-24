/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:02:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:34:48 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	// std::cout << GREEN << "Cure constructed." << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	// std::cout << GREEN << "Cure copy constructor called." << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	// std::cout << GREEN << "Cure assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	// std::cout << RED << "Cure destructed." << RESET << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}


void Cure::use(ICharacter& target) {
	std::cout << "*"  BOLD GREEN " heals " RESET << target.getName() << "'s wounds *" << std::endl;
}

