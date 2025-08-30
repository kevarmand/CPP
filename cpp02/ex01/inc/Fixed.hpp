/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:00:04 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 19:27:27 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define ORANGE			"\033[93m"				/* Yellow */
# define YELLOW			"\033[38;5;226m"		/* Bright Blue*/
# define GREY			"\033[90m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */

#include <iostream>


/**
 * A class representing a fixed-point number with various constructors,
 * conversion methods, and overloaded operators.
 * 
 * Overflow and underflow are not handled in this implementation.
 */
class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(float value);
	Fixed(int value);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	//utility
	void print(std::ostream& os) const;

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;


private:
	// membres privés
	int 				_value;
	static const int 	_fractionalBits = 8;
};
	
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP