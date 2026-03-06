/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:52:45 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/05 18:58:59 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

#include <iostream>   // std::cout, std::endl
#include <string>     // std::string
#include <limits>     // std::numeric_limits
#include <cctype>     // std::isprint
#include <cmath>      // std::isnan, std::isinf
#include <cstdlib>    // std::strtod

void	printInvalid();
void	printPseudo(std::string const &str);
void	printChar(double value);
void	printInt(double value);
void	printFloat(double value);
void	printDouble(double value);

#endif
