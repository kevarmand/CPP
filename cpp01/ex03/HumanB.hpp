/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:57:29 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 18:02:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();

	void attack() const;
	void setWeapon(Weapon& weapon);
private:
	// membres privés
	std::string _name;
	Weapon* _weapon;
};

#endif // HUMANB_HPP