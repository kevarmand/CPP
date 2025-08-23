/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:30:55 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 12:10:04 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include "color.hpp"

#define CLEAR "\033[2J\033[1;1H" // Clear console

int main() {
	PhoneBook phoneBook;

	std::string command;
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, command)) {
            if (std::cin.eof()) {            // Ctrl+D / EOF
                std::cout << RED "\nEOF\n" RESET;
                break;
            }
            std::cin.clear();
            continue;
		}
		if (command == "ADD") {
			phoneBook.add();
		} else if (command == "SEARCH") {
			phoneBook.search();
		} else if (command == "EXIT") {
			std::cout << "Exiting PhoneBook.\n";
			break;
		} else {
			std::cout << RED << "Unknown command. Please use ADD, SEARCH, or EXIT.\n" << RESET;
		}
		std::cin.clear();
	}
	return 0;
}