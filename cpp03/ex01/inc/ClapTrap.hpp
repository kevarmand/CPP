/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:23:45 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 18:47:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

# define CLEAR			"\033[2J\033[1;1H"	/* Clear the terminal */
#define NO_BOLD			"\033[22m"  		/* <- désactive le bold, conserve la couleur */


# define RESET			"\033[0m"				/* Reset */
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define ORANGE			"\033[93m"				/* Yellow */
# define YELLOW			"\033[38;5;226m"		/* New Yellow */
# define BLUE			"\033[94m"				/* Bright Blue*/
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */
# define BROWN			"\033[33m"			  /* Brown */
# define NGREEN			"\033[38;5;82m"  /* New Green */
#define BLUE_STD		"\033[34m"              /* standard blue */



# define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
#define BOLDBLUE		"\033[1m\033[94m" 		/* Bold Bright Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"		/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */

#define BLUE_SOFT     "\033[38;2;120;170;255m"
#define BOLD_BLUE_SOFT "\033[1m\033[38;2;120;170;255m"

class ClapTrap {
public:
	ClapTrap(const std::string& name = "Default");
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif // CLAPTRAP_HPP