/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 19:30:42 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


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
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD CYAN << "----- ADDITIONAL TESTS -----" << RESET << std::endl;
		std::cout << CYAN "     -test Int Min(stack)" RESET << std::endl;
		std::cout << GREY " \"Fixed d;\" " RESET;
		Fixed d;
		
		std::cout << GREY " \"d.setRawBits(-2147483648);\" " RESET;
		d.setRawBits(-2147483648);
		std::cout << GREY " \"std::cout << d.getRawBits() << std::endl;\" " RESET;
		std::cout << d.getRawBits() << std::endl;
		std::cout << std::endl;

		std::cout << CYAN "     -test Int Max(Heap)" RESET << std::endl;
		std::cout << GREY " \"Fixed* e = new Fixed();\" " RESET;
		Fixed* e = new Fixed();
		std::cout << GREY " \"e->setRawBits(2147483647);\" " RESET;
		e->setRawBits(2147483647);
		std::cout << GREY " \"std::cout << e->getRawBits() << std::endl;\" " RESET;
		std::cout << e->getRawBits() << std::endl;
		std::cout << GREY " \"delete e;\" " RESET;
		delete e;
		std::cout << std::endl;

		std::cout << CYAN "     -test Copy assignment operator" RESET << std::endl;

		std::cout << GREY " \"Fixed f;\" " RESET;
		Fixed f;
		std::cout << GREY " \"d.setRawBits(42);\" " RESET;
		d.setRawBits(42);
		std::cout << GREY " \"f = d;\" " RESET;
		f = d;
		std::cout << std::endl;
		std::cout << CYAN "     -test Copy constructor" RESET << std::endl;
		std::cout << GREY " \"Fixed g(f);\" " RESET;
		Fixed g(f);
		std::cout << std::endl;
		std::cout << CYAN "End of scope" RESET << std::endl;
	}
	return 0;
}