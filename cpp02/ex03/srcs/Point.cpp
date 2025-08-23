/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:25:27 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 13:07:06 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
	// constructeur par défaut
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	// constructeur avec paramètres
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	// constructeur de copie
}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		// copie des membres
	}
	return *this;
}

Point::~Point() {
	// destructeur
}

const Fixed& Point::getX() const {
	return (_x);
}

const Fixed& Point::getY() const {
	return (_y);
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << "(" << obj.getX() << ", " << obj.getY() << ")";
	return os;
}