/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:31:00 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/28 08:22:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include "color.hpp"

PhoneBook::PhoneBook()
: _currentIndex(0), _totalContacts(0) {
}

PhoneBook::PhoneBook(const PhoneBook& other) {
	*this = other;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this != &other) {
		this->_currentIndex = other._currentIndex;
		this->_totalContacts = other._totalContacts;
		for (int i = 0; i < MAX_CONTACTS; ++i) {
			this->_contacts[i] = other._contacts[i];
		}
	}
	return *this;
}

PhoneBook::~PhoneBook() {
	// destructeur
}

int PhoneBook::logicalToPhysical(int logical) const {
	if (_totalContacts < MAX_CONTACTS) return logical;
		return (_currentIndex + logical) % MAX_CONTACTS;
}

void PhoneBook::add() {
	Contact tmp;

	if (!tmp.fillFromInput()) {
		std::cout << RED << "Failed to add contact.\n" << RESET;
		std::cin.clear();
		return;
	}
	_contacts[_currentIndex] = tmp;
	if (_totalContacts < MAX_CONTACTS)
		++_totalContacts;
	_currentIndex = (_currentIndex + 1) % MAX_CONTACTS;
	std::cout << BOLDGREEN << "Contact saved.\n" << RESET;
}

void PhoneBook::search() const {
	if (_totalContacts == 0) {
		std::cout << RED << "No contacts available.\n" << RESET;
		return;
	}
	std::cout << "\n|" << BOLDYELLOW
			  << std::setw(10) << "Index" << RESET << "|" << BOLDBLUE
			  << std::setw(10) << "First Name" << RESET << "|" << BOLD_BLUE_SOFT
			  << std::setw(10) << "Last Name" << RESET << "|" << BOLDCYAN
			  << std::setw(10) << "Nickname" << RESET << "|\n";
	for (int i = 0; i < _totalContacts; ++i) {
		int p = logicalToPhysical(i);
		_contacts[p].displayShort(i);
	}
	std::cout << "Enter index to view full contact (0 to " << _totalContacts - 1 << "): ";

	std::string input;
	std::getline(std::cin, input);
	if (input.size() != 1) {
		std::cout << RED << "Invalid index.\n" << RESET;
		return;
	}
	unsigned char uc = static_cast<unsigned char>(input[0]);
	int idx = uc - '0';
	if (idx < 0 || idx >= _totalContacts) {
		std::cout << RED << "Index out of range.\n" << RESET;
		return;
	}
	_contacts[logicalToPhysical(idx)].displayFull();
}