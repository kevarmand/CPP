/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:02:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 23:15:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed():_value(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) :_value(other._value) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	// Alternatively, you could use:
	// _value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;	
}

int Fixed::getRawBits() const {
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << YELLOW << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}