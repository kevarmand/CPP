/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:05:18 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 18:25:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>


MateriaSource::MateriaSource() : materiaCount(0) {
	for (int i = 0; i < 4; ++i) {
		materias[i] = 0;
	}
	// std::cout << GREEN << "MateriaSource constructed." << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : materiaCount(other.materiaCount) {
	for (int i = 0; i < 4; ++i) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
	}
	// std::cout << GREEN << "MateriaSource copy constructor called." << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << GREEN << "MateriaSource assignment operator called." << RESET << std::endl;
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
		}
	}
	// std::cout << RED << "MateriaSource destructed." << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (materiaCount >= 4) {
		std::cout << YELLOW << "MateriaSource is full. Cannot learn more materia." << RESET << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (materias[i] == 0) {
			materias[i] = m;
			materiaCount++;
			// std::cout << GREEN << "Learned materia of type " << m->getType() << "." << RESET << std::endl;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (materias[i] && materias[i]->getType() == type) {
			// std::cout << GREEN << "Creating materia of type " << type << "." << RESET << std::endl;
			return materias[i]->clone();
		}
	}
	std::cout << YELLOW << "Materia of type " << type << " not found." << RESET << std::endl;
	return 0;
}
