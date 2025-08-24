/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:32:00 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:28:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "color.hpp"

class Fire : public AMateria {
public:
	Fire();
	Fire(const Fire& other);
	Fire& operator=(const Fire& other);
	~Fire();

	AMateria* clone() const;
	void use(ICharacter& target);

private:
	// membres privés
};

#endif // FIRE_HPP