/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:05:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 18:38:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>


MateriaSource::MateriaSource() : materiaCount(0) {
	for (int i = 0; i < 4; ++i) {
		materias[i] = 0;
	}
	std::cout << E_MS
			<< GREEN BOLD UNDERLINE "[MateriaSource]" NO_UNDERLINE NO_BOLD
			<< " Spellbook of Knowledge opened." << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
: materiaCount(other.materiaCount) {
	for (int i = 0; i < 4; ++i) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
	}
	std::cout << E_MS
			<< YELLOW BOLD UNDERLINE "[MateriaSource]" NO_UNDERLINE NO_BOLD
			<< " copy constructed." << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << E_MS
			<< YELLOW BOLD UNDERLINE "[MateriaSource]" NO_UNDERLINE NO_BOLD
			<< " assignment operator called." << RESET << std::endl;
	if (this != &other) {
		materiaCount = other.materiaCount;
		for (int i = 0; i < 4; ++i) {
			if (materias[i]) {
				delete materias[i];
			}
			if (other.materias[i]) {
				materias[i] = other.materias[i]->clone();
			} else {
				materias[i] = 0;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (materias[i]) {
			delete materias[i];
			materias[i] = 0;
		}
	}
	std::cout << E_MS
			<< RED BOLD UNDERLINE "[MateriaSource]" NO_UNDERLINE NO_BOLD
			<< " Spellbook of Knowledge sealed." << RESET << std::endl;
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

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << E_MS
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Cannot learn null materia." 
			<< RESET << std::endl;
		return;
	}
	if (materiaCount >= 4) {
		std::cout << E_MS
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Cannot learn more materia, Compendium full." 
			<< RESET << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (materias[i] == 0) {
			materias[i] = m;
			materiaCount++;
			std::cout << E_MS
				<< RESET "Learned materia of type " 
				<< get_color(m->getType()) << m->getType() 
				<< RESET << "." << std::endl;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (materias[i] && materias[i]->getType() == type) {
			std::cout << E_MS
					<< RESET << "Creating materia of type " 
					<< get_color(type) << type << RESET << "." << std::endl;
			return materias[i]->clone();
		}
	}
	std::cout << E_MS
			<< BOLD ORANGE "[WARNING]" RESET
			<< " Materia of type \"" << get_color(type) << type 
			<< RESET "\" not learned." << std::endl;
	return 0;
}
