/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chaos.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:21:04 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chaos.hpp"
#include "ICharacter.hpp"
#include <iostream>


Chaos::Chaos() : AMateria("chaos") {
	// std::cout << GREEN << "Chaos constructed." << RESET << std::endl;
}

Chaos::Chaos(const Chaos& other) : AMateria(other) {
	// std::cout << GREEN << "Chaos copy constructor called." << RESET << std::endl;
}

Chaos& Chaos::operator=(const Chaos& other) {
	// std::cout << GREEN << "Chaos assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Chaos::~Chaos() {
	// std::cout << RED << "Chaos destructed." << RESET << std::endl;
}

AMateria* Chaos::clone() const {
	return new Chaos(*this);
}

void Chaos::use(ICharacter& target) {
	std::cout << "* unleashes a" BOLD MAGENTA " Chaos Bolt" RESET " on " << target.getName() << "'s head *" << std::endl;
}