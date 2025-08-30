/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:41:46 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 09:57:33 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << CLEAR;


	//Faisons des test clairs : s aussurez-vous que les test de base sont ok
	{
		std::cout << BOLD CYAN "\n--- TESTS DE BASE ---\n" RESET << std::endl;
		std::cout << BOLD YELLOW "Creating a Dog" RESET << std::endl;
		std::cout << std::endl << GREY << "const AAnimal* dog = new Dog(); " RESET;
		const AAnimal* dog = new Dog();
		std::cout << std::endl<< GREY << "dog->makeSound(); " RESET;
		dog->makeSound();
		std::cout << std::endl << GREY << "delete dog; " RESET;
		delete dog;
	}
	// ----------------TEST ECHOUANT A LA COMPILATION----------------
	{
		// ----------------Class non instanciable----------------
		// AAnimal animal;
	}
	{
		// ----------------Class non instanciable----------------
		//AAnimal* animal = new AAnimal();
	}
	{
		// ----------------Tableau d'objets----------------
		//AAnimal arr[10];
	}
	{
		// ----------------Slicing----------------
		//AAnimal animal = Dog();
	}
	return 0;
}