/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:02:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 13:14:11 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath> 

Fixed::Fixed():_value(0) {
	//std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) :_value(other._value) {
	//std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	// Alternatively, you could use:
	// _value = other.getRawBits();
}

Fixed::Fixed(int value) {
	//std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	// no overflow check for simplicity
	_value = value << _fractionalBits; 
}

Fixed::Fixed(float value) {
	//std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}


Fixed& Fixed::operator=(const Fixed& other) {
	//std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	//std::cout << RED << "Destructor called" << RESET << std::endl;	
}

int Fixed::getRawBits() const {
	//std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << YELLOW << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}


// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	if (other._value == 0) {
		std::cerr << RED << "Error: Division by zero" << RESET << std::endl;
		return Fixed(0); // or handle as appropriate
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement operators
Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

// Min / Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}



// Overload of the insertion operator for easy output

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}










































