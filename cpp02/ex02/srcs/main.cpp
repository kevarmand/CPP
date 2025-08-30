/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/29 19:17:40 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


#define CLEAR "\033[2J\033[1;1H"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
// # define ORANGE			"\033[93m"				/* Yellow */
// # define YELLOW			"\033[38;5;226m"		/* New Yellow */
// # define BLUE			"\033[94m"				/* Bright Blue*/
// # define MAGENTA		"\033[35m"				/* Magenta */
// # define BROWN			"\033[33m"			  /* Brown */


#define BROWN
#define BLINK  "\x1b[5m"	// Blink
#define COLOR_A "\033[35m"	// Magenta"
#define COLOR_B "\033[33m"	// Brown
#define COLOR_C	"\033[94m"	// Bright Blu
#define COLOR_D "\033[93m"	// Orange
#define COLOR_E "\033[32m"	// Green
#define COLOR_F "\033[38;5;226m"	// Yellow







inline void wait_enter(const char* msg = "\n[Press Enter to continue] ") {
	std::cout << BLINK << msg << RESET << std::flush;
	std::string dump;
	std::getline(std::cin, dump);
	std::cout << CLEAR;
}

int main( void ) {
	{
		std::cout << CLEAR;
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << BOLD CYAN << "-------- TEST --------" << RESET << std::endl;
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << CYAN "    - exemple subject" RESET << std::endl;
		std::cout << std::endl;


		Fixed a;
		Fixed const b( Fixed( -4 ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	wait_enter();
	{
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << BOLD CYAN << "------COMPARISON------" << RESET << std::endl;
		std::cout << BOLD CYAN << "----------------------" << std::endl;


		std::cout << std::endl;

		std::cout << RESET CYAN "--test with " BOLD "a < b" RESET << std::endl;
		std::cout << GREY " \"Fixed a(" RESET "1.5f" GREY "); Fixed b(" RESET "2.5f" GREY ");\" " RESET << std::endl;
		Fixed a(1.5f);
		Fixed b(2.5f);
		std::cout << GREY "std::cout << " RESET "(a < b)" GREY " << std::endl;\" " RESET;
		std::cout << (a < b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a > b)" GREY " << std::endl;\" " RESET;
		std::cout << (a > b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a <= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a <= b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a >= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a >= b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a == b)" GREY " << std::endl;\" " RESET;
		std::cout << (a == b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a != b)" GREY " << std::endl;\" " RESET;
		std::cout << (a != b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << RESET CYAN "--test with " BOLD "a > b" RESET << std::endl;
		std::cout << GREY " \"Fixed a(" RESET "-3.42f" GREY "); Fixed b(" RESET "-51.1f" GREY ");\" " RESET << std::endl;
		a = Fixed(-3.42f);
		b = Fixed(-51.1f);
		std::cout << GREY "std::cout << " RESET "(a < b)" GREY " << std::endl;\" " RESET;
		std::cout << (a < b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a > b)" GREY " << std::endl;\" " RESET;
		std::cout << (a > b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a <= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a <= b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a >= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a >= b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a == b)" GREY " << std::endl;\" " RESET;
		std::cout << (a == b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a != b)" GREY " << std::endl;\" " RESET;
		std::cout << (a != b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << std::endl << std::endl;

		std::cout << RESET CYAN "--test with " BOLD "a == b" RESET << std::endl;
		std::cout << GREY " \"Fixed a(" RESET "42.42f" GREY "); Fixed b(" RESET "42.42f" GREY ");\" " RESET << std::endl;
		a = Fixed(42.42f);
		b = Fixed(42.42f);
		std::cout << GREY "std::cout << " RESET "(a < b)" GREY " << std::endl;\" " RESET;
		std::cout << (a < b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a > b)" GREY " << std::endl;\" " RESET;
		std::cout << (a > b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a <= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a <= b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a >= b)" GREY " << std::endl;\" " RESET;
		std::cout << (a >= b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a == b)" GREY " << std::endl;\" " RESET;
		std::cout << (a == b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a != b)" GREY " << std::endl;\" " RESET;
		std::cout << (a != b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << std::endl<< std::endl;

		
		std::cout << RESET CYAN "--test with PRECISION" RESET << std::endl;
		a = Fixed(123.1234f); 
		b = Fixed(123.1266f);
		std::cout << GREY " \"Fixed a(" RESET "123.1234f" GREY "); Fixed b(" RESET "123.1266f" GREY ");\" " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a == b)" GREY " << std::endl;\" " RESET;
		std::cout << (a == b) << CYAN " (expected: 1) " RESET << std::endl;
		std::cout << std::endl;
		a=Fixed(123.1234f);
		b=Fixed(123.123f);
		std::cout << GREY " \"Fixed a(" RESET "123.1234f" GREY "); Fixed b(" RESET "123.123f" GREY ");\" " RESET << std::endl;
		std::cout << GREY "std::cout << " RESET "(a == b)" GREY " << std::endl;\" " RESET;
		std::cout << (a == b) << CYAN " (expected: 0) " RESET << std::endl;
		std::cout << std::endl;

	}
	wait_enter();
	{
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << BOLD CYAN << "-------ARITHMETIC-----" << RESET << std::endl;
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << std::endl;

		std::cout << RESET CYAN "--Definition of " BOLD COLOR_A "a" RESET ", "
				<< BOLD COLOR_B "b" RESET ", " BOLD COLOR_C "c" RESET
				<< ", " BOLD COLOR_D "d" RESET << ", " BOLD COLOR_E "e" RESET 
				<< " and " BOLD COLOR_F "f" RESET << std::endl;
		std::cout << GREY "Fixed " COLOR_A "a" GREY "(" RESET "3.14159f" GREY ");  " RESET; 
		Fixed a(-3.14159f);
		std::cout << a << std::endl;

		std::cout << GREY "Fixed " COLOR_B "b" GREY "(" RESET "0.003f" GREY ");  " RESET;
		Fixed b(0.003f);
		std::cout << b << std::endl;

		std::cout << GREY "Fixed " COLOR_C "c" GREY "(" RESET "4242424.4242f" GREY ");  " RESET;
		Fixed c(4242424.4242f);
		std::cout << c << std::endl;
		
		Fixed d(-0.0f);
		std::cout << GREY "Fixed " COLOR_D "d" GREY "(" RESET "-0.0f" GREY ");  " RESET;
		std::cout << d << std::endl;

		Fixed e(0.4242f);
		std::cout << GREY "Fixed " COLOR_E "e" GREY "(" RESET "0.4242f" GREY ");  " RESET;
		std::cout << e << std::endl;

		Fixed f(4242424);
		std::cout << GREY "Fixed " COLOR_F "f" GREY "(" RESET "4242424" GREY ");  " RESET;
		std::cout << f << std::endl;
		
		std::cout << std::endl;

		//Addition
		std::cout << RESET BOLD CYAN "--ADDITION--" RESET << std::endl;
		std::cout << COLOR_A "a" RESET " + " COLOR_B "b" RESET " = ";
		std::cout << (a + b) << std::endl;

		//b + d
		std::cout << COLOR_B "b" RESET " + " COLOR_D "d" RESET " = ";
		std::cout << (b + d) << std::endl;

		//d + c
		std::cout << COLOR_D "d" RESET " + " COLOR_C "c" RESET " = ";
		std::cout << (d + c) << std::endl;
		
		//e + f
		std::cout << COLOR_E "e" RESET " + " COLOR_F "f" RESET " = ";
		std::cout << (e + f) << std::endl;
		std::cout << std::endl;

		//b + b
		std::cout << COLOR_B "b" RESET " + " COLOR_B "b" RESET " = ";
		std::cout << (b + b) << std::endl;

		//f + f
		std::cout << RESET CYAN "here we try overflow : " << std::endl;
		std::cout << COLOR_F "f" RESET " + " COLOR_F "f" RESET " = ";
		std::cout << (f + f) << std::endl;
		std::cout << std::endl;

		//Subtraction
		std::cout << RESET BOLD CYAN "--SUBTRACTION--" RESET << std::endl;
		std::cout << COLOR_A "a" RESET " - " COLOR_B "b" RESET " = ";
		std::cout << (a - b) << std::endl;

		//b - d
		std::cout << COLOR_B "b" RESET " - " COLOR_D "d" RESET " = ";
		std::cout << (b - d) << std::endl;
		//d - c
		std::cout << COLOR_D "d" RESET " - " COLOR_C "c" RESET " = ";
		std::cout << (d - c) << std::endl;

		//c - e
		std::cout << COLOR_C "c" RESET " - " COLOR_E "e" RESET " = ";
		std::cout << (c - e) << std::endl;

		//c - f
		std::cout << COLOR_C "c" RESET " - " COLOR_F "f" RESET " = ";
		std::cout << (c - f) << std::endl;

		//d-f-f
		std::cout << RESET CYAN "here we try overflow : " << std::endl;
		std::cout << COLOR_D "d" RESET " - " COLOR_F "f" RESET " - " COLOR_F "f" RESET " = ";
		std::cout << (d - f - f) << std::endl;
		std::cout << std::endl;

		//Multiplication
		std::cout << RESET BOLD CYAN "--MULTIPLICATION--" RESET << std::endl;
		std::cout << COLOR_A "a" RESET " * " COLOR_B "b" RESET " = ";
		std::cout << (a * b) << std::endl;

		//b * d
		std::cout << COLOR_B "b" RESET " * " COLOR_D "d" RESET " = ";
		std::cout << (b * d) << std::endl;
		//d * c
		std::cout << COLOR_D "d" RESET " * " COLOR_C "c" RESET " = ";
		std::cout << (d * c) << std::endl;
		
		//c * e
		std::cout << COLOR_C "c" RESET " * " COLOR_E "e" RESET " = ";
		std::cout << (c * e) << std::endl;

		//a * f
		std::cout << RESET CYAN "here we try overflow : " << std::endl;
		std::cout << COLOR_A "a" RESET " * " COLOR_F "f" RESET " = ";
		std::cout << (a * f) << std::endl;
		std::cout << std::endl;

		//Division
		std::cout << RESET BOLD CYAN "--DIVISION--" RESET << std::endl;
		std::cout << COLOR_A "a" RESET " / " COLOR_B "b" RESET " = ";
		std::cout << (a / b) << std::endl;

		//a / f
		std::cout << COLOR_A "a" RESET " / " COLOR_F "f" RESET " = ";
		std::cout << (a / f) << std::endl;

		//d / c
		std::cout << COLOR_D "d" RESET " / " COLOR_C "c" RESET " = ";
		std::cout << (d / c) << std::endl;

		
		// f / a
		std::cout << COLOR_F "f" RESET " / " COLOR_A "a" RESET " = ";
		std::cout << (f / a) << std::endl;

		//b / d
		std::cout << RESET CYAN "here we try division by zero : " << std::endl;
		std::cout << COLOR_B "b" RESET " / " COLOR_D "d" RESET " = ";
		std::cout << (b / d) << std::endl;

		//c / e
		std::cout << RESET CYAN "here we try overflow : " << std::endl;
		std::cout << COLOR_C "c" RESET " / " COLOR_E "e" RESET " = ";
		std::cout << (c / e) << std::endl;

	}
	wait_enter();
	{
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << BOLD CYAN << "----INCREMENT/DECREMENT" << RESET << std::endl;
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << std::endl;

		Fixed a(0);
		Fixed reset_a = a;
		std::cout << GREY " \"Fixed " COLOR_A "a" GREY " (" RESET "0" GREY ");\" " RESET<< std::endl;

		//int max
		Fixed b(0);
		
		b.setRawBits(2147483647);
		Fixed reset_b = b;
		std::cout << GREY " \"Fixed " COLOR_B "b" GREY " (" RESET "0" GREY "); b.setRawBits(2147483647);\" " RESET;
		std::cout <<  "b =" << b << std::endl;
		
		//int min
		Fixed c(0);
		c.setRawBits(-2147483648);
		Fixed reset_c = c;
		std::cout << GREY " \"Fixed " COLOR_C "c" GREY " (" RESET "0" GREY "); c.setRawBits(-2147483648);\" " RESET;
		std::cout <<  "c =" << c << std::endl;
		std::cout << std::endl;

		//Ce qu on veut un petit tableau sur 5 colone : 
		// Premier colone : l instruction en GREY
		// Deuxieme colone : la valeur avant
		// Troisieme colone : la valeur retourner par l operation
		// Quatrieme colone : la valeur apres
		// Cinquieme colone : le resultat attendu en

		std::cout << GREY "Instruction" RESET "\t| Before\t| Return\t  | After" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		
		std::cout << GREY "	++" COLOR_A "a" GREY << "\t| " RESET << a << "\t\t| " << ++a << "\t  | " << a << std::endl;
		a = reset_a;
		std::cout << GREY COLOR_A "	a" "++" GREY << "\t| " RESET << a << "\t\t| " << a++ << "\t\t  | " << a  << std::endl;
		a = reset_a;
		std::cout << GREY "	--" COLOR_A "a" GREY << "\t| " RESET << a << "\t\t| " << --a << "\t  | " << a << std::endl;
		a = reset_a;
		std::cout << GREY COLOR_A "	a" "--" GREY << "\t| " RESET << a << "\t\t| " << a-- << "\t\t  | " << a << std::endl;
		a = reset_a;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		std::cout << GREY "	++" COLOR_B "b" GREY << "\t| " RESET << b << "| " ; ++b;
		b = reset_b;
		std::cout << GREY "	" COLOR_B "b" "++" GREY << "\t| " RESET << b << "| ";  b++;
		b = reset_b;
		std::cout << GREY "	--" COLOR_B "b" GREY << "\t| " RESET << b << "| " << --b << "  | " << b << std::endl;
		b = reset_b;
		std::cout << GREY "	" COLOR_B "b" "--" GREY << "\t| " RESET << b << "| " << b-- << "  | " << b << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		std::cout << GREY "	++" COLOR_C "c" GREY << "\t| " RESET << c << "\t| " << ++c << " | " << c << std::endl;
		c = reset_c;
		std::cout << GREY "	" COLOR_C "c" "++" GREY << "\t| " RESET << c << "\t| " << c++ << "\t  | " << c << std::endl;
		c = reset_c;
		std::cout << GREY "	--" COLOR_C "c" GREY << "\t| " RESET << c << "\t| "; --c;
		c = reset_c;
		std::cout << GREY "	" COLOR_C "c" "--" GREY << "\t| " RESET << c << "\t| "; c--;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	//wait_enter();
	{
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << BOLD CYAN << "-------- MIN/MAX ------" << RESET << std::endl;
		std::cout << BOLD CYAN << "----------------------" << std::endl;
		std::cout << std::endl;

		Fixed a(1.5f);
		Fixed b(2.5f);
		const Fixed c(3.5f);
		const Fixed d(4.5f);

		std::cout << GREY " \"Fixed " COLOR_A "a" GREY "(" RESET "1.5f" GREY "); Fixed " COLOR_B "b" GREY "(" RESET "2.5f" GREY ");\" " RESET << std::endl;
		std::cout << GREY " \"const Fixed " COLOR_C "c" GREY "(" RESET "3.5f" GREY "); const Fixed " COLOR_D "d" GREY "(" RESET "4.5f" GREY ");\" " RESET << std::endl;
		std::cout << std::endl;

		//min
		std::cout << GREY "std::cout << " RESET "Fixed::min(" COLOR_A "a" RESET ", " COLOR_B "b" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::min(a, b) << CYAN " (expected: 1.5) " RESET << std::endl;
		//max(a, b);
		std::cout << GREY "std::cout << " RESET "Fixed::max(" COLOR_A "a" RESET ", " COLOR_B "b" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::max(a, b) << CYAN " (expected: 2.5) " RESET << std::endl;
		std::cout << std::endl;

		//min(c, d);
		std::cout << GREY "std::cout << " RESET "Fixed::min(" COLOR_C "c" RESET ", " COLOR_D "d" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::min(c, d) << CYAN " (expected: 3.5) " RESET << std::endl;
		//max(c, d);
		std::cout << GREY "std::cout << " RESET "Fixed::max(" COLOR_C "c" RESET ", " COLOR_D "d" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::max(c, d) << CYAN " (expected: 4.5) " RESET << std::endl;
		std::cout << std::endl;

		//min(b, c);
		std::cout << GREY "std::cout << " RESET "Fixed::min(" COLOR_B "b" RESET ", " COLOR_C "c" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::min(b, c) << CYAN " (expected: 2.5) " RESET << std::endl;
		//max(b, c);
		std::cout << GREY "std::cout << " RESET "Fixed::max(" COLOR_B "b" RESET ", " COLOR_C "c" RESET ")" GREY " << std::endl;\" " RESET;
		std::cout << Fixed::max(b, c) << CYAN " (expected: 3.5) " RESET << std::endl;
		std::cout << std::endl;
	}
	return 0;
}