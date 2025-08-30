/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lightning.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:03:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:38:35 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lightning.hpp"
#include "ICharacter.hpp"
#include <iostream>


Lightning::Lightning() : AMateria("lightning") {
	std::cout << E_LTG
			<< GREEN BOLD "[" UNDERLINE YELLOW "Lightning" NO_UNDERLINE
			<< GREEN "]" NO_BOLD
			<< " constructed." << RESET << std::endl;
}

Lightning::Lightning(const Lightning& other) : AMateria(other) {
	std::cout << E_LTG
			<< YELLOW BOLD "[" UNDERLINE YELLOW "Lightning" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " copy constructor called." << RESET << std::endl;
}

Lightning& Lightning::operator=(const Lightning& other) {
	std::cout << E_LTG
			<< YELLOW BOLD "[" UNDERLINE YELLOW "Lightning" NO_UNDERLINE
			<< YELLOW "]" NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Lightning::~Lightning() {
	std::cout << E_LTG
			<< RED BOLD "[" UNDERLINE YELLOW "Lightning" NO_UNDERLINE
			<< RED "]" NO_BOLD
			<< " destructed." << RESET << std::endl;
}

AMateria* Lightning::clone() const {
	return new Lightning(*this);
}
//* storms converge — lightning strikes <name> with blinding flash *
void Lightning::use(ICharacter& target) {
	std::cout << E_LTG
		<< "* storms converge — " BOLD YELLOW "lightning" RESET " strikes " << target.getName() << " with blinding flash *" << std::endl;
}