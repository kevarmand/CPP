/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:47:48 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 21:30:43 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	// constructeur par défaut
}

Harl::~Harl() {
	// destructeur
}

void Harl::debug() const {
	std::cout << GREEN "[ DEBUG ]" RESET " : " GREY;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() const {
	std::cout << YELLOW "[ INFO ]" RESET " : " GREY; 
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const {
	std::cout << ORANGE "[ WARNING ]" RESET " : " GREY;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
	
void Harl::error()  const {
	std::cout << RED "[ ERROR ]" RESET " : " GREY;
	std::cout << "This is unacceptable! I want to speak to the manager now." RESET << std::endl;
}

void Harl::complain(std::string& level) const{
	static void (Harl::* const functions[])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	static const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < sizeof(levels) / sizeof(levels[0]); i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}