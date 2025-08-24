/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:35:28 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "ICharacter.hpp"
#include <iostream>


Fire::Fire() : AMateria("fire") {
	// std::cout << GREEN << "Fire constructed." << RESET << std::endl;
}

Fire::Fire(const Fire& other) : AMateria(other) {
	// std::cout << GREEN << "Fire copy constructor called." << RESET << std::endl;
}

Fire& Fire::operator=(const Fire& other) {
	// std::cout << GREEN << "Fire assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Fire::~Fire() {
	// std::cout << RED << "Fire destructed." << RESET << std::endl;
}

AMateria* Fire::clone() const {
	return new Fire(*this);
}

void Fire::use(ICharacter& target) {
	std::cout << "* ignites a " BOLD FIRE_CLR "Pyroblast" RESET "; a blazing orb streaks into " << target.getName() << "'s head and detonates *" << std::endl;
}