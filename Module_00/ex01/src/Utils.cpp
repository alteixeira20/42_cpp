#include "../inc/Utils.hpp"

void	ft_print(const std::string &str, bool endl)
{
	std::cout << str;
	if (endl)
		std::cout << std::endl;
}
