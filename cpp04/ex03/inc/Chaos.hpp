/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chaos.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:32:00 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 19:12:27 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Chaos_HPP
#define Chaos_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "color.hpp"

class Chaos : public AMateria {
public:
	Chaos();
	Chaos(const Chaos& other);
	Chaos& operator=(const Chaos& other);
	~Chaos();

	AMateria* clone() const;
	void use(ICharacter& target);

private:
	// membres privés
};

#endif // Chaos_HPP