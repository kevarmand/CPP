/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:14:30 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 15:14:46 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

const std::string Cat::emoji = "🐱  ";

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << Cat::emoji
		<< BOLD GREEN "Cat created: " RESET ORANGE
		<< _type << RESET << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << Cat::emoji
		<< BOLD GREEN "Cat copied: " RESET ORANGE
		<< _type << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
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

void Cat::setIdea(int index, const std::string& idea) {
	this->_brain->setIdea(index, idea);
}

void Cat::getIdea(int index) const {
	std::string idea = this->_brain->getIdea(index);
	if (!idea.empty()) {
		std::cout << Cat::emoji
			<< BOLD GREEN "Cat's idea at index " RESET ORANGE
			<< index << RESET BOLD GREEN ": " RESET
			<< idea << std::endl;
	} else {
		std::cout << Cat::emoji
			<< BOLD RED "No idea found at index " RESET ORANGE
			<< index << RESET BOLD RED "." RESET << std::endl;
	}
}