/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:02:22 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 19:19:15 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <sstream>  // ostringstream
#include <cmath> 
#include <limits>


Fixed::Fixed():_value(0) {
	//std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) :_value(other._value) {
	//std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed::Fixed(int value) {
	//std::cout << GREEN << "Int constructor called" << RESET << std::endl;

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
	//std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	//std::cout << RED << "Destructor called" << RESET << std::endl;	
}

Fixed::Fixed(float value) {
	//std::cout << GREEN << "Float constructor called" << RESET << std::endl;

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

	if (*this < 0) {
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
#include <limits>

Fixed Fixed::operator+(const Fixed& other) const {
	const int a = this->getRawBits();
	const int b = other.getRawBits();

	long long s = static_cast<long long>(a) + static_cast<long long>(b);
	if (s > std::numeric_limits<int>::max()
		|| s < std::numeric_limits<int>::min()) {
		std::cerr << RED << "Overflow (fixed + fixed)" << RESET << std::endl;
		s = 0;
	}
	Fixed r;
	r.setRawBits(static_cast<int>(s));
	return r;
}

Fixed Fixed::operator-(const Fixed& other) const {
	const int a = this->getRawBits();
	const int b = other.getRawBits();

	long long diff = static_cast<long long>(a) - static_cast<long long>(b);
	if (diff > std::numeric_limits<int>::max()
		|| diff < std::numeric_limits<int>::min()) {
		std::cerr << RED << "Overflow (fixed - fixed)" << RESET << std::endl;
		diff = 0;
	}
	Fixed r;
	r.setRawBits(static_cast<int>(diff));
	return r;
}

Fixed Fixed::operator*(const Fixed& other) const {
	long long product = static_cast<long long>(this->getRawBits())
		* static_cast<long long>(other.getRawBits());

	product >>= _fractionalBits;

	if (product > std::numeric_limits<int>::max()
		|| product < std::numeric_limits<int>::min()) {
		std::cerr << RED << "Overflow (fixed * fixed)" << RESET << std::endl;
		product = 0;
	}
	Fixed result;
	result.setRawBits(static_cast<int>(product));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._value == 0) {
		std::cerr << RED << "Error: Division by zero" << RESET << std::endl;
		return Fixed(0);
	}
	const int a = this->getRawBits();
	const int b = other.getRawBits();
	// Séparer les signes pour éviter le left-shift signé (UB)
	const bool neg = ((a < 0) ^ (b < 0));
	unsigned int ua = (a < 0) ? static_cast<unsigned int>(-a) : static_cast<unsigned int>(a);
	unsigned int ub = (b < 0) ? static_cast<unsigned int>(-b) : static_cast<unsigned int>(b);

	// Promouvoir en 64 bits non signés et left-shift SANS UB
	unsigned long long num = static_cast<unsigned long long>(ua);
	// Si tu veux vraiment "protéger", tu peux vérifier le risque de dépassement ULL ici.
	num <<= _fractionalBits; // sûr : shift sur unsigned

	// Division entière positive
	if (ub == 0) { // déjà testé, mais gardé pour la tranquillité d'esprit
		std::cerr << RED << "Error: Division by zero" << RESET << std::endl;
		return Fixed(0);
	}
	unsigned long long uq = num / static_cast<unsigned long long>(ub);

	// Remettre le signe
	long long q_signed = neg ? -static_cast<long long>(uq) : static_cast<long long>(uq);

	// Clamp vers int si nécessaire (politique à choisir ; ici saturation)
	if (q_signed > std::numeric_limits<int>::max()
	 || q_signed < std::numeric_limits<int>::min())
	{
		std::cerr << RED << "Overflow (fixed / fixed)" << RESET << std::endl;
		q_signed = 0;
	}
	Fixed r;
	r.setRawBits(static_cast<int>(q_signed));
	return r;
}

// Increment / Decrement operators
Fixed& Fixed::operator++() {
	if (_value == std::numeric_limits<int>::max()) {
		std::cerr << RED << "Overflow (++fixed)" << RESET << std::endl;
		return *this;
	}
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	if (_value == std::numeric_limits<int>::max()) {
		std::cerr << RED << "Overflow (fixed++)" << RESET << std::endl;
		return *this;
	}
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	if (_value == std::numeric_limits<int>::min()) {
		std::cerr << RED << "Underflow (--fixed)" << RESET << std::endl;
		return *this;
	}
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	if (_value == std::numeric_limits<int>::min()) {
		std::cerr << RED << "Underflow (fixed--)" << RESET << std::endl;
		return *this;
	}
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
	obj.print(os);
	return os;
}