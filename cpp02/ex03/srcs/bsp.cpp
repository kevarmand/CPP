/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:29:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 12:56:47 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"


//operation : AB x AP (composant z)
static Fixed cross(Point const& a, Point const& b, Point const& point) {
	return (b.getX() - a.getX()) * (point.getY() - a.getY())
		- (b.getY() - a.getY()) * (point.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed area2 = cross(a, b, c);
	if (area2 == Fixed(0))
		return false;

	Fixed c1 = cross(a, b, point);
	Fixed c2 = cross(b, c, point);
	Fixed c3 = cross(c, a, point);

	if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0))
		return false;

	bool hasNeg = (c1 < Fixed(0)) || (c2 < Fixed(0)) || (c3 < Fixed(0));
	bool hasPos = (c1 > Fixed(0)) || (c2 > Fixed(0)) || (c3 > Fixed(0));

	
	return !(hasNeg && hasPos);
}