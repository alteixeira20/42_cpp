/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:01:27 by alteixeira20      #+#    #+#             */
/*   Updated: 2025/11/21 15:08:40 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_upper(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		std::cout << static_cast<char>(std::toupper(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		print_upper(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
