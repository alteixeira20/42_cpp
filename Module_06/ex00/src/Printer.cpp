/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:10:48 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/05 20:01:46 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

void	printInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	printPseudo(std::string const &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	printChar(double value)
{
	char	c;

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static bool isIntLike(double value)
{
	if (std::isnan(value) || std::isinf(value))
		return (false);
	if (value == static_cast<double>(static_cast<long long>(value)))
		return (true);
	else
		return (false);
}

void	printFloat(double value)
{
	float	f;

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	f = static_cast<float>(value);
	if (isIntLike(value))
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}



void	printDouble(double value)
{
	if (isIntLike(value))
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}
