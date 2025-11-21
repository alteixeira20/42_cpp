#include "../inc/Contact.hpp"

Contact::Contact()
{
	_firstName	= "";
	_lastName	= "";
	_nickname	= "";
	_phoneNumber	= "";
	_darkestSecret	= "";
}

void	Contact::setContact(const std::string &firstName,
			 const std::string &lastName,
			 const std::string &nickname,
			 const std::string &phoneNumber,
			 const std::string &darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_phoneNumber = phoneNumber;
	_nickname = nickname;
	_darkestSecret = darkestSecret;
}

bool	Contact::isEmpty() const
{
	return _firstName.empty();
}

std::string	Contact::getFirstName() const
{
	return _firstName;
}

std::string	Contact::getLastName() const
{
	return _lastName;
}

std::string	Contact::getNickname() const
{
	return _nickname;
}

void	Contact::displayFullInfo() const
{
	std::cout << "First Name:	" << _firstName << std::endl;
	std::cout << "Last Name:	" << _lastName << std::endl;
	std::cout << "Nickname:	" << _nickname << std::endl;
	std::cout << "Phone Number:	" << _phoneNumber << std::endl;
	std::cout << "Darkest Secret:	" << _darkestSecret << std::endl;
}
