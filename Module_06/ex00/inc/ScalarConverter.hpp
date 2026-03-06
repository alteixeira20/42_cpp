/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:15:08 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/04 16:40:04 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter
{
	public:
		static void	convert(std::string const &str);
	private:
		// def ctor
		ScalarConverter();
		// cpy ctor
		ScalarConverter(const ScalarConverter &other);
		// assign operator
		ScalarConverter& operator=(const ScalarConverter &other);
		// destructor
		~ScalarConverter();
};

#endif
