/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:40:34 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 14:51:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
		Zombie( std::string name = "default" );
		~Zombie();

		void announce( void ) const;

	private:
		std::string _name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif // ZOMBIE_HPP