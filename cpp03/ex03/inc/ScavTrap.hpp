/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:05:10 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 20:07:48 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(const std::string& name="Default_ScavTrap");
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	virtual ~ScavTrap();
	
	static const int defaultHitPoints = 100;
	static const int defaultEnergyPoints = 50;
	static const int defaultAttackDamage = 20;
	
	void attack(const std::string& target);
	void guardGate();

protected:
	bool _guardMode;

};

#endif // SCAVTRAP_HPP