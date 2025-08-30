/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:02:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 19:32:21 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath> 

Fixed::Fixed():_value(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) :_value(other._value) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed::Fixed(int value) {
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;

	const int F = _fractionalBits;
	if (value > (std::numeric_limits<int>::max() >> F) ||
		value < (std::numeric_limits<int>::min() >> F)) {
		std::cerr << RED << "Overflow (int -> fixed)" << RESET << std::endl;
		_value = 0;
		return;
	}
	_value = value << F;
}


Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;	
}

Fixed::Fixed(float value) {
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;

	const int F = _fractionalBits;
	const float scale = static_cast<float>(1 << F);

	// 1) Rejeter NaN/Inf
	if (!std::isfinite(value)) {
		std::cerr << RED << "Invalid float (NaN/Inf)" << RESET << std::endl;
		_value = 0;
		return;
	}

	// 2) Plage max/min représentable avant arrondi
	const float maxVal = std::numeric_limits<int>::max() / scale;
	const float minVal = std::numeric_limits<int>::min() / scale;

	if (value > maxVal || value < minVal) {
		std::cerr << RED << "Overflow (float -> fixed)" << RESET << std::endl;
		_value = 0;
		return;
	}

	//3) Conversion
	_value = static_cast<int>(roundf(value * scale));
}

void Fixed::setRawBits(int const raw) {
	std::cout << YELLOW << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return (roundf(this->toFloat()));
}



/***
 * Print the real decimal part
 * Note: This function respects the current precision of the output stream.
 *
 * @param os The output stream
 */
void Fixed::print(std::ostream& os) const {
	const int F = _fractionalBits;
	int int_part = _value >> F;
	int mask = (1 << F) - 1;
	int frac_raw = _value & mask;

	if (_value < 0) {
		if (frac_raw != 0)
		{
			frac_raw = (1 << F) - frac_raw;
			int_part += 1; // ajuster la partie entière si nécessaire
		}
	}
	
	os << int_part;
	if (frac_raw == 0)
		return;

	float frac_part = frac_raw / (float)(1 << F);

	std::ostringstream tmp;
	tmp.setf(os.flags());
	tmp.precision(os.precision());
	tmp << frac_part;
	std::string s = tmp.str();

	if (!s.empty() && s[0] == '0')
		s.erase(0, 1);
	os << s;
	return;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	obj.print(os);
	return os;
}