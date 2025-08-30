/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chaos.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 14:35:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chaos.hpp"
#include "ICharacter.hpp"
#include <iostream>


Chaos::Chaos() : AMateria("chaos") {
	std::cout << E_CHS
			<< GREEN BOLD "[" UNDERLINE MAGENTA "Chaos" NO_UNDERLINE 
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Chaos::Chaos(const Chaos& other) : AMateria(other) {
	std::cout << E_CHS
			<< YELLOW BOLD "[" UNDERLINE MAGENTA "Chaos" NO_UNDERLINE 
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Chaos& Chaos::operator=(const Chaos& other) {
	std::cout << E_CHS
			<< YELLOW BOLD "[" UNDERLINE MAGENTA "Chaos" NO_UNDERLINE 
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Chaos::~Chaos() {
	std::cout << E_CHS
			<< RED BOLD "[" UNDERLINE MAGENTA "Chaos" NO_UNDERLINE 
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Chaos::clone() const {
	std::cout << E_CHS
			<< BOLD "[" UNDERLINE MAGENTA "Chaos" NO_UNDERLINE 
			<< RESET BOLD "]" NO_BOLD
			<< " cloned." << RESET << std::endl;
	return new Chaos(*this);
}

void Chaos::use(ICharacter& target) {
	std::cout << E_CHS
			<< "* unleashes a" BOLD MAGENTA " Chaos Bolt" RESET 
			<< " on " << target.getName() << "'s head *" << std::endl;
}