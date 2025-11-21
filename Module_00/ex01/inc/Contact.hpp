#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		
		void		setContact(const std::string &firstName,
					const std::string &lastName,
					const std::string &nickname,
					const std::string &phoneNumber,
					const std::string &darkestSecret);
		
		bool		isEmpty() const;

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		
		void		displayFullInfo() const;
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
