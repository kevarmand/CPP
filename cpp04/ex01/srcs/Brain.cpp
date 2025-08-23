/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:59:33 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/23 23:04:21 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
	std::cout << BOLD GREEN "A New Brain is born with thoughts!" RESET
			<< std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << BOLD GREEN "A Brain is copied, thoughts duplicated!" RESET
			<< std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
		std::cout << BOLD GREEN "A Brain is assigned, thoughts copied!" RESET
				<< std::endl;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << BOLD RED "Brain is being destroyed, thoughts fading away..."
			<< RESET << std::endl;
}