/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 13:27:34 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <limits>
#include <cmath>

#define CLEAR "\033[2J\033[1;1H"
#define RESET "\033[0m"
#define BOLD "\033[1m"

#define CYAN "\033[36m"

int main( void ) {
	{
		std::cout << CLEAR;
		std::cout << BOLD CYAN << "----- EX00 TESTS -----" << RESET << std::endl;
		std::cout << CYAN "     test ennonce" RESET << std::endl;
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << BOLD CYAN << "----- ADDITIONAL TESTS -----" << RESET << std::endl;
		std::cout << CYAN "     -test Int Min(stack)" RESET << std::endl;
		std::cout << GREY " \"Fixed d;\" " RESET;
		Fixed d;
		std::cout << GREY " \"d.setRawBits(-2147483648);\" " RESET;
		d.setRawBits(-2147483648);
		std::cout << GREY " \"std::cout << d << std::endl;\" " RESET;
		std::cout << d << std::endl;
		std::cout << GREY " \"std::cout << d.toInt() << std::endl;\" " RESET;
		std::cout << d.toInt() << std::endl;
		std::cout << GREY " \"std::cout << d.toFloat() << std::endl;\" " RESET;
		std::cout << d.toFloat() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << CYAN "     -test Constructor with Float" RESET << std::endl;
		std::cout << GREY " \"Fixed e( -3.14159f );\" " RESET;
		Fixed e( -3.14159f );
		std::cout << GREY " \"std::cout << e << std::endl;\" " RESET;
		std::cout << e << std::endl;
		std::cout << GREY " \"std::cout << e.toInt() << std::endl;\" " RESET;
		std::cout << e.toInt() << std::endl;
		std::cout << GREY " \"std::cout << e.toFloat() << std::endl;\" " RESET;
		std::cout << e.toFloat() << std::endl;
		
		
		std::cout << std::endl;
		std::cout << GREY " \"e = 2.71828f;\" " RESET;
		e = 2.71828f;
		std::cout << GREY " \"std::cout << e << std::endl;\" " RESET;
		std::cout << e << std::endl;
		std::cout << GREY " \"std::cout << e.toInt() << std::endl;\" " RESET;
		std::cout << e.toInt() << std::endl;
		std::cout << GREY " \"std::cout << e.toFloat() << std::endl;\" " RESET;
		std::cout << e.toFloat() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << BOLD CYAN << "----- OVERFLOW TESTS -----" << RESET << std::endl;
		std::cout << CYAN "     -test overflow Int constructor" RESET << std::endl;
		std::cout << GREY " \"Fixed f( 10000000 );\" " RESET;
		Fixed f( 10000000 );
		std::cout << GREY " \"std::cout << f << std::endl;\" " RESET;
		std::cout << f << std::endl;
		std::cout << std::endl;
		
		std::cout << CYAN "     -test overflow Float constructor" RESET << std::endl;
		std::cout << GREY " \"Fixed g( -1000000.25f );\" " RESET;
		Fixed g( -10000000.25f );
		std::cout << GREY " \"std::cout << g << std::endl;\" " RESET;
		std::cout << g << std::endl;


		std::cout << std::endl;
		std::cout << CYAN "	 -test NaN Float constructor" RESET << std::endl;
		std::cout << GREY " \"Fixed h( NAN );\" " RESET;
		Fixed h( NAN );
		std::cout << GREY " \"std::cout << h << std::endl;\" " RESET;
		std::cout << h << std::endl;
		std::cout << std::endl;
		std::cout << CYAN "	 -test +Inf Float constructor" RESET << std::endl;
		std::cout << GREY " \"Fixed i( INFINITY );\" " RESET;
		Fixed i( INFINITY );
		std::cout << GREY " \"std::cout << i << std::endl;\" " RESET;
		std::cout << i << std::endl;
	}
	return 0;
}