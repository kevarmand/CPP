/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:00:04 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 23:05:53 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define ORANGE			"\033[93m"				/* Yellow */
# define YELLOW			"\033[38;5;226m"				/* Bright Blue*/
# define GREY			"\033[38;5;253m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	// membres privés
	int                 _value;
	static const int    _fractionalBits = 8;
};

#endif // FIXED_HPP