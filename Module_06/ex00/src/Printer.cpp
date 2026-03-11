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
#include <cmath>
#include <sstream>

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

static std::string	formatDecimal(double value)
{
	std::ostringstream	out;
	std::string			text;

	out << value;
	text = out.str();
	if (text.find('.') == std::string::npos
		&& text.find('e') == std::string::npos
		&& text.find('E') == std::string::npos)
		text += ".0";
	return (text);
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
	std::cout << "float: " << formatDecimal(static_cast<double>(f)) << "f" << std::endl;
}

void	printDouble(double value)
{
	std::cout << "double: " << formatDecimal(value) << std::endl;
}
