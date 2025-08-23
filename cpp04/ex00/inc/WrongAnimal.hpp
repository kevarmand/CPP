/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:16:08 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 22:19:32 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include "color.hpp"

class WrongAnimal {
public:
	WrongAnimal(const std::string& type = "WrongAnimal");
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();


	void makeSound() const;// dans ce sujet c est pas virtual
	static const std::string emoji;
	
protected:
	std::string _type;

};

#endif // WRONGANIMAL_HPP