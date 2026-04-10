/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:35:48 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 16:03:10 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

static std::string	trim(const std::string &str)
{
	std::string::size_type	start;
	std::string::size_type	end;

	start = 0;
	end = str.size();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;

	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;

	return (str.substr(start, end - start));
}

static bool	isLeapYear(int y)
{
	if (y % 400 == 0)
		return (true);
	if (y % 100 == 0)
		return (false);
	return (y % 4 == 0);
}

static void	setDaysPerMonth(int daysInMonth[12])
{
	daysInMonth[0] = 31;
	daysInMonth[1] = 28;
	daysInMonth[2] = 31;
	daysInMonth[3] = 30;
	daysInMonth[4] = 31;
	daysInMonth[5] = 30;
	daysInMonth[6] = 31;
	daysInMonth[7] = 31;
	daysInMonth[8] = 30;
	daysInMonth[9] = 31;
	daysInMonth[10] = 30;
	daysInMonth[11] = 31;
}

static bool	isValidDateFormat(const std::string &date)
{
	int	y;
	int	m;
	int	d;
	int	daysInMonth[12];
	int	i;

	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	i = 0;
	while (i < 10)
	{
		if (i == 4 || i == 7)
		{
			i++;
			continue ;
		}
		if (date[i] < '0' || date[i] > '9')
			return (false);
		i++;
	}

	y = (date[0] - '0') * 1000
		+ (date[1] - '0') * 100
		+ (date[2] - '0') * 10
		+ (date[3] - '0');
	m = (date[5] - '0') * 10 + (date[6] - '0');
	d = (date[8] - '0') * 10 + (date[9] - '0');

	if (m < 1 || m > 12)
		return (false);

	setDaysPerMonth(daysInMonth);

	if (m == 2 && isLeapYear(y))
		daysInMonth[1] = 29;

	if (d < 1 || d > daysInMonth[m - 1])
		return (false);

	return (true);
}

static bool	parseDouble(const std::string &str, double &out)
{
	char	*end;
	double	val;

	end = NULL;
	val = std::strtod(str.c_str(), &end);
	if (end == str.c_str())
		return (false);
	while (*end != '\0' && std::isspace(static_cast<unsigned char>(*end)))
		end++;
	if (*end != '\0')
		return (false);
	out = val;
	return (true);
}

static double	parseValue(const std::string &valueStr, const std::string &line)
{
	double	value;

	if (!parseDouble(valueStr, value))
		throw BitcoinExchange::InputError("Error: bad input => " + line);
	if (value < 0.0)
		throw BitcoinExchange::InputError("Error: not a positive number.");
	if (value > 1000.0)
		throw BitcoinExchange::InputError("Error: too large a number.");
	return (value);
}

static bool	splitCsvLine(const std::string &line, std::string &outDate, std::string &outRateStr)
{
	std::string::size_type	pos;

	pos = line.find(',');
	if (pos == std::string::npos)
		return (false);

	outDate = trim(line.substr(0, pos));
	outRateStr = trim(line.substr(pos + 1));

	if (outDate.empty() || outRateStr.empty())
		return (false);

	return (true);
}

static bool	splitInputLine(const std::string &line, std::string &outDate, std::string &outValueStr)
{
	std::string::size_type	pos;

	pos = line.find('|');
	if (pos == std::string::npos)
		return (false);

	outDate = trim(line.substr(0, pos));
	outValueStr = trim(line.substr(pos + 1));

	if (outDate.empty() || outValueStr.empty())
		return (false);

	return (true);
}

/* OCF */
BitcoinExchange::BitcoinExchange(): _rates()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _rates(other._rates)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/* Public Methods */
void	BitcoinExchange::loadDatabase(const std::string &csvFile)
{
	std::ifstream	file;
	std::string	line;

	file.open(csvFile.c_str());
	if (!file.is_open())
		throw BitcoinExchange::DatabaseError("Error: could not open database file.");
	if (!std::getline(file, line))
		throw BitcoinExchange::DatabaseError("Error: empty database file.");

	while (std::getline(file, line))
	{
		std::string	date;
		std::string	rateStr;
		double		rate;

		if (line.empty())
			continue ;
		if (!splitCsvLine(line, date, rateStr))
			throw BitcoinExchange::DatabaseError("Error: bad database line => " + line);
		if (!isValidDateFormat(date))
			throw BitcoinExchange::DatabaseError("Error: bad database date => " + date);
		if (!parseDouble(rateStr, rate))
			throw BitcoinExchange::DatabaseError("Error: bad database rate => " + rateStr);
		_rates[date] = rate;
	}
}

double	BitcoinExchange::findSpecificRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it;
	it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it == _rates.begin())
		throw BitcoinExchange::InputError("Error: bad input => " + date);
	--it;
	return (it->second);
}

void	BitcoinExchange::processInputFile(const std::string &inputFile) const
{
	std::ifstream	file;
	std::string	line;

	file.open(inputFile.c_str());
	if (!file.is_open())
		throw BitcoinExchange::FileError("Error: could not open file.");
	if (!std::getline(file, line))
		return ;

	while (std::getline(file, line))
	{
		try
		{
			std::string	date;
			std::string	valueStr;
			double		value;
			double		rate;
			double		result;

			if (line.empty())
				continue ;

			if (!splitInputLine(line, date, valueStr))
				throw BitcoinExchange::InputError("Error: bad input => " + line);
			if (!isValidDateFormat(date))
				throw BitcoinExchange::InputError("Error: bad input => " + date);

			value = parseValue(valueStr, line);
			rate = findSpecificRate(date);
			result = value * rate;

			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const BitcoinExchange::InputError &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
