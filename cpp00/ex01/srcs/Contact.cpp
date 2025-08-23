/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:30:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 12:09:44 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "color.hpp"

Contact::Contact() {
	// constructeur par défaut
	//on initilise els liste vide  iou  cest fait de base ?
}

Contact::Contact(const Contact& other) {
	*this = other;
}

Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_nickname = other._nickname;
		this->_phoneNumber = other._phoneNumber;
		this->_darkestSecret = other._darkestSecret;
	}
	return *this;
}

Contact::~Contact() {
	// destructeur
}

static void trim_inplace(std::string& s) {

	while (!s.empty() && (s[0] == ' ' || s[0] == '\t')) s.erase(0, 1);
	while (!s.empty() && (s[s.size()-1] == ' ' || s[s.size()-1] == '\t')) s.erase(s.size()-1);
}

bool Contact::promptNonEmpty(const char* label, std::string& out) {
	while(true) {
		std::cout << label;
		if (!std::getline(std::cin, out)) return false;
		trim_inplace(out);
		if (!out.empty()) return true;
		std::cout << RED << "Field cannot be empty.\n" << RESET;
	}
}

static bool isDigits(const std::string& str) {
	for (std::string::size_type i = 0; i < str.size(); ++i) {
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

bool Contact::	fillFromInput() {
	std::string fn, ln, nn, ph, ds;
	
	if (!promptNonEmpty(BLUE "First name: " RESET, fn)) return false;
	if (!promptNonEmpty(BLUE_SOFT "Last name: " RESET, ln))  return false;
	if (!promptNonEmpty(CYAN "Nickname: " RESET, nn))   return false;
	while (true) {
		if (!promptNonEmpty(YELLOW "Phone number: " RESET, ph)) return false;
		if(isDigits(ph)) break;
		std::cout << RED << "Phone number must contain only digits.\n" << RESET;
	} 
	if (!promptNonEmpty(MAGENTA "Darkest secret: " RESET, ds)) return false;

	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickname = nn;
	this->_phoneNumber = ph;
	this->_darkestSecret = ds;

	return true;
}

void Contact::displayFull() const {
	std::cout << BOLDBLUE << "First Name     : " << NO_BOLD << this->_firstName << "\n"
			  << BOLD_BLUE_SOFT << "Last Name      : " << NO_BOLD << this->_lastName << "\n"
			  << BOLDCYAN << "Nickname       : " << NO_BOLD << this->_nickname << "\n"
			  << BOLDYELLOW << "Phone Number   : " << NO_BOLD << this->_phoneNumber << "\n"
			  << BOLDMAGENTA << "Darkest Secret : " << NO_BOLD << this->_darkestSecret << "\n" << RESET;
}

/***
 * Truncate a string to a maximum length and append a dot if it exceeds the limit.
 * and display in rightaligned format.
 */
static std::string truncate(const std::string& str, std::size_t maxLength) {
	if (str.length() > maxLength) {
		return str.substr(0, maxLength - 1) + ".";
	}
	return str;
}

void Contact::displayShort(int index) const {
	std::cout << "|" << YELLOW
			  << std::setw(10) << index << RESET << "|" << BLUE
			  << std::setw(10) << truncate(this->_firstName, 10) << RESET << "|" << BLUE_SOFT
			  << std::setw(10) << truncate(this->_lastName, 10) << RESET << "|" << CYAN
			  << std::setw(10) << truncate(this->_nickname, 10) << RESET << "|\n";
}