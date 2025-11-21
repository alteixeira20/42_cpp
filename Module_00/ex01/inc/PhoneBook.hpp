#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip> // Table Formatting
#include <string>
#include <iostream>

class	PhoneBook
{
	public:
		PhoneBook();

		void	addContact();
		void	search() const;
		void	displayContacts() const;
	private:
		Contact	_contacts[8];
		int	_index;
};

#endif
