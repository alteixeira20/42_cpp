/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:39:04 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/05 19:01:32 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Printer.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

enum	LiteralType
{
	TYPE_PSEUDO,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

static size_t	skipSign(std::string const &str)
{
	if (str[0] == '+' || str[0] == '-')
		return (1);
	else
		return (0);
}

static bool	endsWithF(std::string const &str)
{
	if (!str.empty() && str[str.size() - 1] == 'f')
		return (true);
	return (false);
}

static bool	isPseudo(std::string const &str)
{
	if (str == "nan" || str == "nanf")
		return (true);
	if (str == "+inf" || str == "-inf")
		return (true);
	if (str == "+inff" || str == "-inff")
		return (true);
	return (false);
}

static bool	isSingleChar(std::string const &str)
{
	if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return (true);
	return (false);
}

static LiteralType	classifyNumeric(bool has_f, int dots)
{
	if (dots == 0 && !has_f)
		return (TYPE_INT);
	if (dots == 1)
	{
		if (has_f)
			return (TYPE_FLOAT);
		else
			return (TYPE_DOUBLE);
	}
	return (TYPE_INVALID);

}

static bool	scanNumericBody(std::string const &str, std::size_t start,
			    std::size_t end, int &dots)
{
	std::size_t	i;
	int		digits = 0;
	
	dots = 0;
	if (start >= end)
		return (false);
	i = start;
	while (i < end)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			digits++;
		else if (str[i] == '.')
		{
			dots++;
			if (dots > 1)
				return (false);
		}
		else
			return (false);
		i++;
	}
	if (digits == 0)
		return (false);
	return (true);
}

static LiteralType	detectType(std::string const &str)
{
	bool		has_f;
	std::size_t	start;
	std::size_t	end;
	int		dots;

	if (str.empty())
		return (TYPE_INVALID);
	if (isPseudo(str))
		return (TYPE_PSEUDO);
	if (isSingleChar(str))
		return (TYPE_CHAR);
	
	start = skipSign(str);
	end = str.length();
	has_f = endsWithF(str);
	
	if (has_f)
		end--;
	if (!scanNumericBody(str, start, end, dots))
		return (TYPE_INVALID);
	return (classifyNumeric(has_f, dots));
}

static bool	parseToDouble(std::string const &str, LiteralType type, double &value)
{
	char	*end;

	end = NULL;
	if (type == TYPE_CHAR)
	{
		value = static_cast<unsigned char>(str[0]);
		return (true);
	}
	if (type == TYPE_FLOAT)
	{
		std::string tmp = str.substr(0, str.size() - 1);
		value = std::strtod(tmp.c_str(), &end);
		if (end && *end == '\0')
			return (true);
		else
			return (false);
	}
	value = std::strtod(str.c_str(), &end);
	if (end && *end == '\0')
		return (true);
	else
		return (false);
}

void	ScalarConverter::convert(std::string const &str)
{
	LiteralType	type;
	double		value;

	type = detectType(str);
	if (type == TYPE_INVALID)
	{
		printInvalid();
		return ;
	}
	if (type == TYPE_PSEUDO)
	{
		printPseudo(str);
		return ;
	}
	if (!parseToDouble(str, type, value))
	{
		printInvalid();
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
