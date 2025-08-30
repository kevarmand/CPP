/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:37:01 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "ICharacter.hpp"
#include <iostream>


Fire::Fire() : AMateria("fire") {
	std::cout << E_FIRE
			<< GREEN BOLD "[" UNDERLINE FIRE_CLR "Fire" NO_UNDERLINE
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Fire::Fire(const Fire& other) : AMateria(other) {
	std::cout << E_FIRE
			<< YELLOW BOLD "[" UNDERLINE FIRE_CLR "Fire" RESET NO_UNDERLINE 
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Fire& Fire::operator=(const Fire& other) {
	std::cout << E_FIRE
			<< YELLOW BOLD "[" UNDERLINE FIRE_CLR "Fire" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Fire::~Fire() {
	std::cout << E_FIRE
			<< RED BOLD "[" FIRE_CLR UNDERLINE "Fire" NO_UNDERLINE
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Fire::clone() const {
	return new Fire(*this);
}

void Fire::use(ICharacter& target) {
	std::cout << E_FIRE
		<< "* ignites a " BOLD FIRE_CLR "Pyroblast" RESET "; a blazing orb streaks into " << target.getName() << "'s head and detonates *" << std::endl;
}