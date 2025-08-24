/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lightning.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:32:00 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:28:03 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_HPP
#define LIGHTNING_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "color.hpp"

class Lightning : public AMateria {
public:
	Lightning();
	Lightning(const Lightning& other);
	Lightning& operator=(const Lightning& other);
	~Lightning();

	AMateria* clone() const;
	void use(ICharacter& target);

private:
	// membres privés
};

#endif // LIGHTNING_HPP