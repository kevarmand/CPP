/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:52:59 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:49:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Chaos.hpp"
#include "Fire.hpp"
#include "Earth.hpp"
#include "Lightning.hpp"
#include "Cure.hpp"
#include "color.hpp"


inline void wait_enter(const char* msg = "\n[Press Enter to continue] ") {
	std::cout << msg << std::flush;
	std::string dump;
	std::getline(std::cin, dump);
	std::cout << CLEAR;
}

int main()
{
	{
		//Scope test MateriaSource

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Fire());
		src->learnMateria(new Earth());
		src->learnMateria(new Lightning()); // Should not be learned, inventory full
		
		delete src;
	}
	wait_enter();
	
	return 0;
}