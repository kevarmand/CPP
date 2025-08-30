/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Earth.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:36:53 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Earth.hpp"
#include "ICharacter.hpp"
#include <iostream>


Earth::Earth() : AMateria("earth") {
	std::cout << E_EAR
			<< GREEN BOLD "[" UNDERLINE BROWN "Earth" NO_UNDERLINE
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Earth::Earth(const Earth& other) : AMateria(other) {
	std::cout << E_EAR
			<< YELLOW BOLD "[" UNDERLINE BROWN "Earth" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Earth& Earth::operator=(const Earth& other) {
	std::cout << E_EAR
			<< YELLOW BOLD "[" UNDERLINE BROWN "Earth" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Earth::~Earth() {
	std::cout << E_EAR
			<< RED BOLD "[" UNDERLINE BROWN "Earth" NO_UNDERLINE 
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Earth::clone() const {
	return new Earth(*this);
}
//* hammers the ground — Earth Shock erupts beneath <name>’s feet *
void Earth::use(ICharacter& target) {
	std::cout << E_EAR
		<< "* hammers the ground — " BOLD BROWN "Earth Shock" RESET " erupts beneath " << target.getName() << "'s feet *" << std::endl;
}