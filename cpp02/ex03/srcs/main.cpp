/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 13:17:12 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

# define RESET			"\033[0m"				/* Reset */
# define BLACK			"\033[30m"				/* Black */
# define BLUE			"\033[94m"				/* Bright Blue*/
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */


# define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
#define BOLDBLUE		"\033[1m\033[94m" 		/* Bold Bright Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"		/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */

#define BLUE_SOFT     "\033[38;2;120;170;255m"
#define BOLD_BLUE_SOFT "\033[1m\033[38;2;120;170;255m"


bool bsp(Point const a, Point const b, Point const c, Point const point);


void test(const Point& p, const Point& a, const Point& b, const Point& c) {
	if (bsp(a, b, c, p))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;
}


int main( void ) {
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);

	std::cout << CYAN << "Testing point with triangle ABC: " << a << b << c << RESET << std::endl;
	std::cout << BLUE << "Point(1, 1): " << RESET "expected: inside" << std::endl;
	test(Point(1, 1), a, b, c);
	std::cout << BLUE << "Point(4, 4): " << RESET "expected: outside" << std::endl;
	test(Point(4, 4), a, b, c);
	std::cout << BLUE << "Point(0, 0): " << RESET "expected: outside (on vertex)" << std::endl;
	test(Point(0, 0), a, b, c);
	std::cout << BLUE << "Point(2, 2): " << RESET "expected: outside (on edge)" << std::endl;
	test(Point(2, 2), a, b, c);
	
	//second part, changing the order of the triangle points
	std::cout << CYAN << "\nTesting point with triangle ABC: " << a << c << b << RESET << std::endl;
	std::cout << BLUE << "Point(1, 1): " << RESET "expected: inside" << std::endl;
	test(Point(1, 1), a, c, b);
	std::cout << BLUE << "Point(4, 4): " << RESET "expected: outside" << std::endl;
	test(Point(4, 4), a, c, b);
	std::cout << BLUE << "Point(0, 0): " << RESET "expected: outside (on vertex)" << std::endl;
	test(Point(0, 0), a, c, b);
	std::cout << BLUE << "Point(2, 2): " << RESET "expected: outside (on edge)" << std::endl;
	test(Point(2, 2), a, c, b);
	return 0;
}	