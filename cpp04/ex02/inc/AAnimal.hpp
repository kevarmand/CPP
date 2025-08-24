/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:08:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/24 15:12:24 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <string>

#include "color.hpp"

class AAnimal {
public:
	AAnimal(const std::string& type = "AAnimal");
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;

	static const std::string emoji;
protected:
	std::string _type;

};

#endif // AAnimal_HPP