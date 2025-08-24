/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Earth.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:26:56 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Earth.hpp"
#include "ICharacter.hpp"
#include <iostream>


Earth::Earth() : AMateria("earth") {
	// std::cout << GREEN << "Earth constructed." << RESET << std::endl;
}

Earth::Earth(const Earth& other) : AMateria(other) {
	// std::cout << GREEN << "Earth copy constructor called." << RESET << std::endl;
}

Earth& Earth::operator=(const Earth& other) {
	// std::cout << GREEN << "Earth assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Earth::~Earth() {
	// std::cout << RED << "Earth destructed." << RESET << std::endl;
}

AMateria* Earth::clone() const {
	return new Earth(*this);
}
//* hammers the ground — Earth Shock erupts beneath <name>’s feet *
void Earth::use(ICharacter& target) {
	std::cout << "* hammers the ground — " BOLD BROWN "Earth Shock" RESET " erupts beneath " << target.getName() << "'s feet *" << std::endl;
}