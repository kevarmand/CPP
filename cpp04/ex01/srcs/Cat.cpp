/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:14:30 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 23:11:36 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

const std::string Cat::emoji = "🐱  ";

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << Cat::emoji
		<< BOLD GREEN "Cat created: " RESET ORANGE
		<< _type << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << Cat::emoji
		<< BOLD GREEN "Cat copied: " RESET ORANGE
		<< _type << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
		std::cout << Cat::emoji
			<< BOLD GREEN "Cat assigned: " RESET ORANGE
			<< _type << RESET << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << Cat::emoji
		<< BOLD RED "Cat [" RESET ORANGE
		<< _type << RED "] destroyed: " RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << Cat::emoji
		<< BOLD "Meow! Meow!" 
		<< RESET << std::endl;
}