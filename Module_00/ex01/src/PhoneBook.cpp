#include "../inc/PhoneBook.hpp"
#include "../inc/Utils.hpp"

PhoneBook::PhoneBook() : _index(0) {}

static std::string	truncateField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return (str);
}

static int	handleFirstName(std::string &firstName)
{
	ft_print("Enter First Name: ", false);
	std::getline(std::cin, firstName);
	if (firstName.empty())
	{
		ft_print("Field cannot be empty!", true);
		return (0);
	}
	return (1);
}

static int	handleLastName(std::string &lastName)
{
	ft_print("Enter Last Name: ", false);
	std::getline(std::cin, lastName);
	if (lastName.empty())
	{
		ft_print("Field cannot be empty!", true);
		return (0);
	}
	return (1);
}

static int	handleNickname(std::string &nickname)
{
	ft_print("Enter Nickname: ", false);
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		ft_print("Field cannot be empty!", true);
		return (0);
	}
	return (1);
}

static int	handlePhoneNumber(std::string &phoneNumber)
{
	ft_print("Enter Phone Number: ", false);
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		ft_print("Field cannot be empty!", true);
		return (0);
	}
	return (1);
}

static int	handleDarkestSecret(std::string &darkestSecret)
{
	ft_print("Enter Darkest Secret: ", false);
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		ft_print("Field cannot be empty!", true);
		return (0);
	}
	return (1);
}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!handleFirstName(firstName))
		return ;
	if (!handleLastName(lastName))
		return ;
	if (!handleNickname(nickname))
		return ;
	if (!handlePhoneNumber(phoneNumber))
		return ;
	if (!handleDarkestSecret(darkestSecret))
		return ;
	_contacts[_index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_index = (_index + 1) % 8;
	ft_print("Contact added successfully.", true);
}

void	PhoneBook::displayContacts() const
{
	int	i;

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	i = 0;
	while (i < 8)
	{
		if (_contacts[i].isEmpty())
		{
			i++;
			continue ;
		}
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateField(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateField(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateField(_contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void	PhoneBook::search() const
{
	std::string	input;
	int		index;

	displayContacts();
	ft_print("Enter the index of the contact: ", false);
	std::getline(std::cin, input);

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		ft_print("Invalid index!", true);
		return ;
	}
	index = input[0] - '0';
	if (_contacts[index].isEmpty())
	{
		ft_print("No contact stored at this index!", true);
		return ;
	}
	_contacts[index].displayFullInfo();
}
