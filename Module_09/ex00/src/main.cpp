/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:22:10 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 13:33:08 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	ex;

		ex.loadDatabase("data.csv");
		ex.processInputFile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
