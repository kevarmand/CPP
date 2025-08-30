/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:41:46 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 09:21:14 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	{
		std::cout << CLEAR;
		
		std::cout << BOLD CYAN "--- Animal Creation ---" RESET 
				<< GREY " Animal* animals[10];" RESET << std::endl;
		Animal* animals[10];

		std::cout << BOLD CYAN "--- Filling the array with Dogs and Cats ---" RESET 
				<< GREY " for (int i = 0; i < 10; i++) { animals[i] = (i % 2 ) ? new Dog() : new Cat(); }" RESET << std::endl;
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << BOLD CYAN "--- Making sounds ---" RESET 
				<< GREY " for (int i = 0; i < 10; i++) { animals[i]->makeSound(); }" RESET << std::endl;
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
		}

		std::cout << BOLD CYAN "--- Deleting Animals ---" RESET 
				<< GREY " for (int i = 0; i < 10; i++) { delete animals[i]; }" RESET << std::endl;
		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}

		std::cout << std::endl << BOLD CYAN "--- Deep Copy Test ---" RESET << std::endl;

		std::cout << BOLD CYAN "Creating dog1" RESET
			<< GREY " Dog dog1; " RESET << std::endl;
		Dog dog1;
		std::cout << BOLD CYAN "Setting idea in dog1" RESET
			<< GREY " dog1.setIdea(0, \"Chase the cat\");" RESET << std::endl;
		dog1.setIdea(0, "Chase the cat");
		std::cout << BOLD CYAN "Creating dog2 as a copy of dog1" RESET
			<< GREY " Dog dog2 = dog1; " RESET << std::endl;
		Dog dog2 = dog1; // Copy constructor
		std::cout << BOLD CYAN "dog2's idea at index 0:" RESET
			<< GREY " dog2.getIdea(0); " RESET << std::endl
			<< "dog2's idea: ";
		dog2.getIdea(0);
		std::cout << std::endl;
		std::cout << BOLD CYAN "Modifying dog2's idea" RESET
			<< GREY " dog2.setIdea(0, \"Eat the bone\");" RESET << std::endl;
		dog2.setIdea(0, "Eat the bone");
		std::cout << BOLD CYAN "dog1's idea at index 0 (should be unchanged):" RESET
			<< GREY " dog1.getIdea(0); " RESET << std::endl
			<< "dog1's idea: " ;
		dog1.getIdea(0);
		std::cout << std::endl;
		std::cout << BOLD CYAN "dog2's idea at index 0 (should be modified):" RESET
			<< GREY " dog2.getIdea(0); " RESET << std::endl
			<< "dog2's idea: ";
		dog2.getIdea(0);
		std::cout << std::endl;
	}
	// {
	// 	//test avec une supresion du mot clef virtual dans la classe Animal
	// 	Animal* animal = new Dog();
	// 	delete animal; // Comportement indéfini si le destructeur n'est pas virtuel
	// }

	return 0;
}