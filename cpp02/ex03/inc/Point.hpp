/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:23:39 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 13:06:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;
	
private:
	// membres privés
	const Fixed _x;
	const Fixed _y;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);

#endif // POINT_HPP