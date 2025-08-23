/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:59:50 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 19:13:55 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap  : public ClapTrap {
public:
	FragTrap(const std::string& name="Default_FragTrap");
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void highFivesGuys();
private:
	// private member
};

#endif // FragTrap_HPP