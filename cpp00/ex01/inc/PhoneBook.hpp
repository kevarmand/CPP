/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:30:46 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 12:13:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
	PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);
	~PhoneBook();

	void add();
	void search() const;

private:
	Contact		_contacts[MAX_CONTACTS];
	int			_currentIndex;
	int			_totalContacts;

	int logicalToPhysical(int index) const;

};



#endif // PHONEBOOK_HPP