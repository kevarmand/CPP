/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:37:36 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice") {
	std::cout << E_ICE
			<< GREEN BOLD "[" UNDERLINE BLUE_SOFT "Ice" RESET NO_UNDERLINE
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << E_ICE
			<< YELLOW BOLD "[" UNDERLINE BLUE_SOFT "Ice" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << E_ICE
			<< YELLOW BOLD "[" UNDERLINE BLUE_SOFT "Ice" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cout << E_ICE
			<< RED BOLD "[" UNDERLINE BLUE_SOFT "Ice" NO_UNDERLINE
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << E_ICE
		<< "* shoots an " BOLD BLUE_SOFT "Ice Bolt" RESET " at " << target.getName() << "'s head *" << std::endl;
}