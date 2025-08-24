/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:54:27 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 18:03:50 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(const std::string& type) : type(type) {
	// std::cout << GREEN << "AMateria of type " << type << " constructed." << RESET << std::endl;
}
AMateria::AMateria(const AMateria& other) : type(other.type) {
	// std::cout << GREEN << "AMateria copy constructor called." << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	// std::cout << GREEN << "AMateria assignment operator called." << RESET << std::endl;
	if (this != &other) {
		// 'type' is const, so we don't assign it
	}
	return *this;
}

AMateria::~AMateria() {
	// std::cout << RED << "AMateria of type " << type << " destructed." << RESET << std::endl;
}

const std::string& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}

