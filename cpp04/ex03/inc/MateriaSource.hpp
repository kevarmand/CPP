/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:18:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/30 12:00:59 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "color.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);

private:
	AMateria*	materias[4];
	int			materiaCount;
};

#endif // MATERIASOURCE_HPP