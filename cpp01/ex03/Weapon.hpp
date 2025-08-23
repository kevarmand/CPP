/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:58:20 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 17:38:58 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();

	const std::string& getType() const;
	void setType(std::string newType);
	
private:
	// membres privés
	std::string _type;
};

#endif // WEAPON_HPP