/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:08:56 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 23:13:57 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

const std::string Dog::emoji = "🐕  ";

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << Dog::emoji
		<< BOLD GREEN "Dog created: " RESET BLUE
		<< _type << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << Dog::emoji
		<< BOLD GREEN "Dog copied: " RESET BLUE
		<< _type << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
		std::cout << Dog::emoji
			<< BOLD GREEN "Dog assigned: " RESET BLUE
			<< _type << RESET << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << Dog::emoji
		<< BOLD RED "Dog [" RESET BLUE
		<< _type << RED "] destroyed: " RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << Dog::emoji
		<< BOLD "Woof! Woof!"
		<< RESET << std::endl;
}