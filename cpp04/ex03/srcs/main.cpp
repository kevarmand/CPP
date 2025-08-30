/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:52:59 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:42:40 by kearmand         ###   ########.fr       */
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
#include <limits>


#define SECTION(title) \
  (std::cout << BOLD << CYAN << "\n------------- " << title << " -------------\n" << RESET)

#define SHOW(cmd) do { \
	std::cout << std::endl << GREY << #cmd << ";" RESET << std::endl; \
	cmd; \
} while (0)

inline void pause_clear(const char* msg = BLINK "\n[Press Enter to continue] " RESET) {
	std::cout << msg << std::flush;
	std::string dump;
	std::getline(std::cin, dump);
	std::cout << CLEAR;
}

inline void pause_inline(const char* msg =  BLINK "\r[Press Enter to continue] " RESET) {
	std::cout << "\r" << msg << std::flush;
	std::string _;
	std::getline(std::cin, _);
	std::cout << "\r\033[2K\033[1A\033[2K\r" << std::flush;
}

static const char* get_color(const std::string& type) {
	if (type == "ice")
		return BLUE_SOFT;
	else if (type == "cure")
		return GREEN;
	else if (type == "fire")
		return FIRE_CLR;
	else if (type == "earth")
		return BROWN;
	else if (type == "lightning")
		return YELLOW;
	else if (type == "chaos")
		return MAGENTA;
	return RESET;
}

int main()
{
	std::cout << CLEAR;
	{
		//Scope test MateriaSource
		SECTION("Test MateriaSource");

		std::cout << CYAN "CREATION " BOLD "countedShadow" RESET << std::endl;
		std::cout << GREY "IMateriaSource* countedShadow = new MateriaSource();" RESET << std::endl;
		IMateriaSource* countedShadow = new MateriaSource();
		pause_inline();
		SHOW(countedShadow->learnMateria(new Ice()));
		SHOW(countedShadow->learnMateria(new Lightning()));
		SHOW(countedShadow->learnMateria(new Fire()));
		SHOW(countedShadow->learnMateria(new Earth()));
		pause_inline();
		std::cout <<std::endl << CYAN "CREATION: " BOLD "bookOfLife" RESET << std::endl << std::endl;
		std::cout << GREY "IMateriaSource bookOfLife = new MateriaSource();" RESET << std::endl;
		IMateriaSource* bookOfLife = new MateriaSource();
		SHOW(bookOfLife->learnMateria(new Chaos()));
		SHOW(bookOfLife->learnMateria(new Chaos()));
		SHOW(bookOfLife->learnMateria(new Cure()));
		pause_clear();
		{
			//On met ce bloc dans un scope car on teste des fonction dont on ne devrait pas avoir access
			// TEST copy constructor, assignment operator and destructor
			SECTION("TEST copy constructor, assignment operator and destructor");
			std::cout << CYAN "At this point, we have two MateriaSource instances:" 
					<< RESET << std::endl;
			std::cout << BOLD "  - countedShadow " RESET "("
					<< get_color("ice") << "ice" RESET ", "
					<< get_color("lightning") << "lightning" RESET ", "
					<< get_color("fire") << "fire" RESET ", "
					<< get_color("earth") << "earth" RESET ")" << std::endl;
			std::cout << BOLD "  - bookOfLife " RESET
					<< "(" << get_color("chaos") << "chaos" RESET ", "
					<< get_color("chaos") << "chaos" RESET ", "
					<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;
			pause_inline();

			std::cout << std::endl << GREY
					<< "MateriaSource *copyOfShadow;"
					<< RESET << std::endl;
			MateriaSource *copyOfShadow;
			
			std::cout << std::endl << GREY
					<< "copyOfShadow = new MateriaSource(*(MateriaSource*)countedShadow);"
					<< RESET << std::endl;			
			copyOfShadow = new MateriaSource(*(MateriaSource*)countedShadow);

			std::cout << std::endl << GREY "MateriaSource copyOfCopy;" RESET << std::endl;
			MateriaSource copyOfCopy;
			
			std::cout << std::endl << GREY "copyOfCopy = *copyOfShadow;" RESET << std::endl;
			copyOfCopy = *copyOfShadow;
			pause_inline();
			SHOW(delete copyOfShadow);

			std::cout << CYAN
					<< std::endl << "fin du scope" << std::endl;
		}
		pause_clear();
		// TEST limite MateriaSource
		SECTION("TEST MateriaSource limits");
		std::cout << CYAN "At this point, we have two MateriaSource instances:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - countedShadow " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl;
		std::cout << BOLD "  - bookOfLife " RESET
				<< "(" << get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;

		std::cout << std::endl << GREY
				<< "AMateria* tmpMat;" RESET << std::endl;
		AMateria* tmpMat;
		pause_inline();
		std::cout << std::endl << UNDERLINE BOLD CYAN "GOOD USAGE:" RESET << std::endl;
		SHOW(tmpMat = countedShadow->createMateria("ice"));
		SHOW(delete tmpMat);
		SHOW(tmpMat = bookOfLife->createMateria("cure"));
		SHOW(delete tmpMat);
		SHOW(tmpMat = countedShadow->createMateria("fire"));
		SHOW(delete tmpMat);
		pause_inline();
		std::cout << std::endl << UNDERLINE BOLD CYAN "BAD USAGE:" RESET << std::endl;
		std::cout << std::endl << CYAN "Inventory full) :" RESET;
		SHOW(countedShadow->learnMateria(new Lightning()));
	
		std::cout << std::endl << CYAN "Type not learned) :" RESET;
		SHOW(tmpMat = countedShadow->createMateria("cure"));
		std::cout << std::endl << CYAN "Null pointer) :" RESET;
		SHOW(countedShadow->learnMateria(0));
		std::cout << std::endl << CYAN " Type unknown) :" RESET;
		SHOW(tmpMat = countedShadow->createMateria("unknown_type"));
		pause_clear();



		//TEST PERSONNAGE
		SECTION("TEST Character");
		std::cout << CYAN "At this point, we have two MateriaSource instances:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - countedShadow " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl;
		std::cout << BOLD "  - bookOfLife " RESET
				<< "(" << get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;
		pause_inline();

		std::cout << std::endl << GREY
				<< "ICharacter* albus << new Character(\"Dumbledore\");"
				<< RESET << std::endl;
		ICharacter* albus = new Character("Dumbledore");
		
		std::cout << std::endl << GREY
				<< "ICharacter* voldemort = new Character(\"Voldemort\");"
				<< RESET << std::endl;
		ICharacter* voldemort = new Character("Voldemort");
		pause_inline();
		SHOW(albus->equip(countedShadow->createMateria("ice")));

		SHOW(tmpMat = countedShadow->createMateria("lightning"));
		SHOW(albus->equip(tmpMat));
		SHOW(albus->equip(bookOfLife->createMateria("cure")));
		SHOW(albus->equip(countedShadow->createMateria("fire")));
		pause_inline();
		SHOW(voldemort->equip(bookOfLife->createMateria("chaos")));
		SHOW(voldemort->equip(bookOfLife->createMateria("chaos")));
		SHOW(voldemort->equip(countedShadow->createMateria("earth")));
		pause_clear();

				std::cout << CYAN "At this point, we have two MateriaSource instances:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - countedShadow " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl;
		std::cout << BOLD "  - bookOfLife " RESET
				<< "(" << get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;
		std::cout << CYAN "And two Characters:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - albus " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("cure") << "cure" RESET ", "
				<< get_color("fire") << "fire" RESET ")" << std::endl;
		std::cout << BOLD "  - voldemort " RESET "("
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl << std::endl;
		pause_inline();

		std::cout << std::endl << UNDERLINE CYAN "GOOD USAGE:" RESET << std::endl;
		SHOW(albus->use(0, *voldemort));
		SHOW(albus->use(1, *voldemort));
		SHOW(albus->use(2, *albus));
		SHOW(albus->use(3, *voldemort));
		pause_inline();
		SHOW(voldemort->use(0, *albus));
		SHOW(voldemort->use(1, *albus));
		SHOW(voldemort->use(2, *albus));
		pause_inline();
		std::cout << std::endl << UNDERLINE CYAN "BAD USAGE:" RESET << std::endl;
		std::cout << std::endl << CYAN "Index too high) :" RESET;
		SHOW(albus->use(4, *voldemort));

		std::cout << std::endl << CYAN "Index negative) :" RESET;
		SHOW(albus->use(-1, *voldemort));

		std::cout << std::endl << CYAN "Slot empty) :" RESET;
		SHOW(voldemort->use(3, *albus));


		pause_clear();
		std::cout << CYAN "At this point, we have two MateriaSource instances:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - countedShadow " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl;
		std::cout << BOLD "  - bookOfLife " RESET
				<< "(" << get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;
		std::cout << CYAN "And two Characters:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - albus " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("cure") << "cure" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< std::endl;
		std::cout << BOLD "  - voldemort " RESET "("
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl << std::endl;
		std::cout << CYAN "ADDITIONAL EQUIP/UNEQUIP:" 
				<< RESET << std::endl;
		pause_inline();
		std::cout << GREY
				<< "AMateria* tempMat2 = bookOfLife->createMateria(\"chaos\");"
				<< RESET << std::endl;
		AMateria* tempMat2 = bookOfLife->createMateria("chaos");
		SHOW(albus->equip(tempMat2));
		SHOW(delete tempMat2);
		SHOW(voldemort->unequip(3));
		SHOW(albus->unequip(1));
		SHOW(albus->use(1, *voldemort));
		SHOW(albus->equip(bookOfLife->createMateria("chaos")));
		SHOW(albus->use(1, *voldemort));

		std::cout <<std::endl << CYAN "End of the test, we are going to delete everything." 
				<< RESET << std::endl;

		pause_clear();
		std::cout << CYAN "At this point, we have two MateriaSource instances:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - countedShadow " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("lightning") << "lightning" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl;
		std::cout << BOLD "  - bookOfLife " RESET
				<< "(" << get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ")" << std::endl << std::endl;
		std::cout << CYAN "And two Characters:" 
				<< RESET << std::endl;
		std::cout << BOLD "  - albus " RESET "("
				<< get_color("ice") << "ice" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("cure") << "cure" RESET ", "
				<< get_color("fire") << "fire" RESET ", "
				<< std::endl;
		std::cout << BOLD "  - voldemort " RESET "("
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("chaos") << "chaos" RESET ", "
				<< get_color("earth") << "earth" RESET ")" << std::endl << std::endl;

		SHOW(delete albus);
		SHOW(delete voldemort);
		pause_inline();
		SHOW(delete tmpMat);
		SHOW(delete countedShadow);
		SHOW(delete bookOfLife);
	}
	return 0;
}