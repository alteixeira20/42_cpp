/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:34:19 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 16:39:08 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <iostream>

int	main(int argc, char **argv)
{
	try
	{
		long	result;

		if (argc != 2)
			throw RPN::Error("Error");

		result = RPN().evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}


	return (0);
}
