/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:51:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 17:55:37 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
	
#include <string>
#include "Weapon.hpp"

class HumanA {
public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack() const;
		
private:
	// membres privés
	std::string _name;
	Weapon& _weapon;
};

#endif // HUMANA_HPP