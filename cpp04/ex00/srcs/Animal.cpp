/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:11:03 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 22:55:23 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include <iostream>

const std::string Animal::emoji = "🐾  ";

Animal::Animal(const std::string& type) : _type(type) {
	std::cout << Animal::emoji
		<< BOLD GREEN "Animal created: " RESET BROWN
		<< _type << RESET << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << Animal::emoji
		<< BOLD GREEN "Animal copied: " RESET BROWN
		<< _type << RESET << std::endl;

}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << Animal::emoji
			<< BOLD GREEN "Animal assigned: " RESET BROWN
			<< _type << RESET << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << Animal::emoji
		<< BOLD RED "Animal [" RESET BROWN
		<< _type << RED "] destroyed: " RESET << std::endl;
}

void Animal::makeSound() const {
	//The animal remains silent, not knowing who it is...”
	std::cout << Animal::emoji
		<< "(The animal remains silent, not knowing who it is...)"
		<< RESET << std::endl;
}