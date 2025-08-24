/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 18:03:33 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice") {
	// std::cout << GREEN << "Ice constructed." << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	// std::cout << GREEN << "Ice copy constructor called." << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	// std::cout << GREEN << "Ice assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	// std::cout << RED << "Ice destructed." << RESET << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << "'s head *" << std::endl;
}