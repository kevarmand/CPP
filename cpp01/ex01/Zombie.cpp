/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:42:40 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 15:19:12 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

# define BOLD			"\033[1m"				/* Bold */
# define NO_BOLD		"\033[22m"				/* No bold */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define RESET			"\033[0m"				/* Reset color */


Zombie::Zombie(std::string name)
:_name(name) {
	std::cout << GREEN BOLD << _name << NO_BOLD
			  << " crawls out of the grave..." RESET << std::endl;
}


Zombie::~Zombie() {
	std::cout << RED BOLD << _name << NO_BOLD 
			  << " collapses into dust !" RESET << std::endl;
}

void	Zombie::announce( void ) const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {
	_name = name;
}