/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:11:03 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 15:14:09 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"
#include <iostream>

const std::string AAnimal::emoji = "🐾  ";

AAnimal::AAnimal(const std::string& type) : _type(type) {
	std::cout << AAnimal::emoji
		<< BOLD GREEN "AAnimal created: " RESET BROWN
		<< _type << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << AAnimal::emoji
		<< BOLD GREEN "AAnimal copied: " RESET BROWN
		<< _type << RESET << std::endl;

}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << AAnimal::emoji
			<< BOLD GREEN "AAnimal assigned: " RESET BROWN
			<< _type << RESET << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << AAnimal::emoji
		<< BOLD RED "AAnimal [" RESET BROWN
		<< _type << RED "] destroyed: " RESET << std::endl;
}
