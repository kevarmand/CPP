/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Earth.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:32:00 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:28:14 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EARTH_HPP
#define EARTH_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "color.hpp"

class Earth : public AMateria {
public:
	Earth();
	Earth(const Earth& other);
	Earth& operator=(const Earth& other);
	~Earth();

	AMateria* clone() const;
	void use(ICharacter& target);

private:
	// membres privés
};

#endif // EARTH_HPP