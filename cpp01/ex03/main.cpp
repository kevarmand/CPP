/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:26 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 09:07:20 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"


# define CYAN			"\033[36m"				/* Cyan */
# define GREY			"\033[90m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */


int main() {
	
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << CYAN << "--- EXTRA TESTS ---" << RESET << std::endl;
		Weapon sword = Weapon("long sword");
		HumanB aragorn("Aragorn");
		aragorn.attack();
		aragorn.setWeapon(sword);
		aragorn.attack();
		sword.setType("Anduril, Flame of the West");
		aragorn.attack();
		HumanA legolas("Legolas", sword);
		legolas.attack();
		sword.setType("Bow of the Galadhrim");
		legolas.attack();
		aragorn.attack();
	}

	return 0;
}