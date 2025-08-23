/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:14:30 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 22:04:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

const std::string WrongCat::emoji = "🐱  ";

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << WrongCat::emoji
		<< BOLD GREEN "WrongCat created: " RESET ORANGE
		<< _type << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << WrongCat::emoji
		<< BOLD GREEN "WrongCat copied: " RESET ORANGE
		<< _type << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		std::cout << WrongCat::emoji
			<< BOLD GREEN "WrongCat assigned: " RESET ORANGE
			<< _type << RESET << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << WrongCat::emoji
		<< BOLD RED "WrongCat [" RESET ORANGE
		<< _type << RED "] destroyed: " RESET << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << WrongCat::emoji
		<< BOLD "Meow! Meow!" 
		<< RESET << std::endl;
}