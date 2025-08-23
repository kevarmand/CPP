/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:11:03 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 22:14:54 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

const std::string WrongAnimal::emoji = "🐾  ";

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
	std::cout << WrongAnimal::emoji
		<< BOLD GREEN "WrongAnimal created: " RESET BROWN
		<< _type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << WrongAnimal::emoji
		<< BOLD GREEN "WrongAnimal copied: " RESET BROWN
		<< _type << RESET << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << WrongAnimal::emoji
			<< BOLD GREEN "WrongAnimal assigned: " RESET BROWN
			<< _type << RESET << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << WrongAnimal::emoji
		<< BOLD RED "WrongAnimal [" RESET BROWN
		<< _type << RED "] destroyed: " RESET << std::endl;
}

void WrongAnimal::makeSound() const {
	//The WrongAnimal remains silent, not knowing who it is...”
	std::cout << WrongAnimal::emoji
		<< "(The WrongAnimal remains silent, not knowing who it is...)"
		<< RESET << std::endl;
}