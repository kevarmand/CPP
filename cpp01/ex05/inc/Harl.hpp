/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:46:43 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 21:30:17 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>


# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define ORANGE			"\033[93m"				/* Yellow */
# define YELLOW			"\033[38;5;226m"				/* Bright Blue*/
# define GREY			"\033[38;5;253m"				/* Grey */
# define RESET			"\033[0m"				/* Reset color */

class Harl {
public:
	Harl();
	~Harl();

	void complain(std::string& level) const;

private:
	// membres privés
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
};

#endif // HARL_HPP