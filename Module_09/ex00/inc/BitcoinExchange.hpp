/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:22:16 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 15:05:11 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		
		void	loadDatabase(const std::string &csvFile);
		void	processInputFile(const std::string &inputFile) const;

		class	FileError: public std::runtime_error
		{
			public:
				FileError(const std::string &msg): std::runtime_error(msg) {}
		};
		class	DatabaseError: public std::runtime_error
		{
			public:
				DatabaseError(const std::string &msg): std::runtime_error(msg) {}
		};
		class	InputError: public std::runtime_error
		{
			public:
				InputError(const std::string &msg): std::runtime_error(msg) {}
		};
	private:
		std::map<std::string, double>	_rates;
		double	findSpecificRate(const std::string &date) const;
};

#endif
