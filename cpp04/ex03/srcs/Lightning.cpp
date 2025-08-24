/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lightning.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:36:47 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lightning.hpp"
#include "ICharacter.hpp"
#include <iostream>


Lightning::Lightning() : AMateria("lightning") {
	// std::cout << GREEN << "Lightning constructed." << RESET << std::endl;
}

Lightning::Lightning(const Lightning& other) : AMateria(other) {
	// std::cout << GREEN << "Lightning copy constructor called." << RESET << std::endl;
}

Lightning& Lightning::operator=(const Lightning& other) {
	// std::cout << GREEN << "Lightning assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Lightning::~Lightning() {
	// std::cout << RED << "Lightning destructed." << RESET << std::endl;
}

AMateria* Lightning::clone() const {
	return new Lightning(*this);
}
//* storms converge — lightning strikes <name> with blinding flash *
void Lightning::use(ICharacter& target) {
	std::cout << "* storms converge — " BOLD YELLOW "lightning" RESET " strikes " << target.getName() << " with blinding flash *" << std::endl;
}