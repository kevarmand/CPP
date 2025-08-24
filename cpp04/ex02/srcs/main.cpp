/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:41:46 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 15:19:03 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << CLEAR;
	
	std::cout << BOLD CYAN "--- AAnimal Creation ---" RESET 
			<< GREY " AAnimal* AAnimals[10];" RESET << std::endl;
	AAnimal* AAnimals[10];

	std::cout << BOLD CYAN "--- Filling the array with Dogs and Cats ---" RESET 
			<< GREY " for (int i = 0; i < 10; i++) { ... }" RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			AAnimals[i] = new Dog();
		else
			AAnimals[i] = new Cat();
	}
	std::cout << BOLD CYAN "--- Making sounds ---" RESET 
			<< GREY " for (int i = 0; i < 10; i++) { ... }" RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		AAnimals[i]->makeSound();
	}

	std::cout << BOLD CYAN "--- Deleting AAnimals ---" RESET 
			<< GREY " for (int i = 0; i < 10; i++) { ... }" RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		delete AAnimals[i];
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

	// Testing abstract class instantiation
	// AAnimal* meta = new AAnimal();
	// delete meta;
	return 0;
}