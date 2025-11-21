#include "../inc/PhoneBook.hpp"
#include "../inc/Utils.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		ft_print("Enter command (ADD, SEARCH, EXIT): ", false);
		if (!std::getline(std::cin, input))
		{
			ft_print("\nEOF detected, exiting.", true);
			break ;
		}
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")
			break ;
		else if (input.empty())
			continue;
		else
			ft_print("Invalid command.", true);
	}
	return (0);
}
