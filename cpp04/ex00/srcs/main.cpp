/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:41:46 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 22:53:27 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << CLEAR;

	// Test Animal, Cat and Dog
	std::cout << BOLD CYAN "--- Testing Animal, Cat and Dog ---" RESET
			<< std::endl << std::endl
			<< CYAN "Creating an Animal :" GREY "Animal* animal = new Animal();" RESET
			<< std::endl;
	Animal* animal = new Animal();
	std::cout << CYAN "Creating a Cat :" GREY "Animal* cat = new Cat();" RESET
			<< std::endl;
	Animal* cat = new Cat();
	std::cout << std::endl
			<< BOLD CYAN "------Making sounds :------"
			<< std::endl
			<< CYAN "Animal :" GREY "animal->makeSound();" RESET
			<< std::endl;
	animal->makeSound();
	std::cout << CYAN "Cat :" GREY "cat->makeSound();" RESET
			<< std::endl;
	cat->makeSound();
	std::cout << std::endl;
	std::cout << CYAN "Deleting Animal :" GREY "delete animal;" RESET
			<< std::endl;
	delete animal;
	std::cout << CYAN "Deleting Cat :" GREY "delete cat;" RESET
			<< std::endl;
	delete cat;
	std::cout << std::endl
			<< CYAN "Creating a Dog :" GREY "Animal* dog = new Dog();" RESET
			<< std::endl;
	Animal* dog = new Dog();
	std::cout << CYAN "Dog :" GREY "dog->makeSound();" RESET
			<< std::endl;
	dog->makeSound();
	std::cout << CYAN "Deleting Dog :" GREY "delete dog;" RESET
			<< std::endl;
	delete dog;
	std::cout << std::endl << std::endl
			<< BOLD CYAN "--- Testing WrongAnimal and WrongCat ---" GREY
			<< "the keyword virtual is missing in WrongAnimal" RESET
			<< std::endl << std::endl;

	std::cout << CYAN "Creating a WrongAnimal :" GREY "WrongAnimal* wrongAnimal = new WrongAnimal();" RESET
			<< std::endl;
	WrongAnimal* wrongAnimal = new WrongAnimal();
	


	// Test WrongAnimal and WrongCat
	std::cout << CYAN "Creating a WrongCat :" GREY 
			<< "WrongAnimal* wrongCat = new WrongCat();" RESET
			<< std::endl;
	WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl
			<< BOLD CYAN "------Making sounds :------"
			<< std::endl
			<< CYAN "WrongAnimal :" GREY "wrongAnimal->makeSound();" RESET
			<< std::endl;
	wrongAnimal->makeSound();
	std::cout << CYAN "WrongCat :" GREY "wrongCat->makeSound();" RESET
			<< std::endl;
	wrongCat->makeSound();

	std::cout << std::endl;
	std::cout << CYAN "Deleting WrongAnimal :" GREY "delete wrongAnimal;" RESET
			<< std::endl;
	delete wrongAnimal;
	std::cout << CYAN "Deleting WrongCat :" GREY "delete wrongCat;" RESET
			<< std::endl;
	delete wrongCat;

	return 0;
}