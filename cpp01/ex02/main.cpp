/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 16:10:12 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define CYAN			"\033[36m"				/* Cyan */
# define GREY			"\033[90m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */



int main() {
	
	//We create a string 
	std::string stringOBJ = "HI THIS IS BRAIN";
	//We create a pointer that points to the string
	std::string* stringPTR = &stringOBJ;
	//We create a reference that refers to the string
	std::string& stringREF = stringOBJ;

	//We print the address of the string
	std::cout << CYAN "ADRESS SECTION :"<< std::endl;
	std::cout << GREY "Adress of str        (&stringOBJ)  :" RESET << &stringOBJ << std::endl;
	std::cout << GREY "Adress held by PTR   (stringPTR)   :" RESET << stringPTR << std::endl;
	std::cout << GREY "Adress held by REF   (&stringREF)  :" RESET << &stringREF << std::endl << std::endl;

	//We print the value of the string
	std::cout << CYAN "VALUE SECTION :"<< std::endl;
	std::cout << GREY "Value of str         (stringOBJ)   :" RESET << stringOBJ << std::endl;
	std::cout << GREY "Value pointed by PTR (*stringPTR)  :" RESET << *stringPTR << std::endl;
	std::cout << GREY "Value pointed by REF (stringREF)   :" RESET << stringREF << std::endl;

	return 0;
}