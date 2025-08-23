/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:40:34 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 15:17:36 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
		Zombie( std::string name = "unknown" );
		~Zombie();

		void announce( void ) const;
		void setName( std::string name );

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP