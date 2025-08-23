/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:50:04 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/21 14:18:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
	
#include <string>

class Contact {
public:
	Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	~Contact();

	bool fillFromInput();

	//Display
	void displayFull() const;
	void displayShort(int index) const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	bool promptNonEmpty(const char* label, std::string& out);
};

#endif // CONTACT_HPP