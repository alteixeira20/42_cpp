/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:29:13 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 16:52:49 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>
#include <iostream>

static void	printTitle(const std::string &title)
{
	std::cout << "=== " << title << " ===" << std::endl;
}

void	testIntBasics()
{
	printTitle("int - basic swap/min/max");

	int a = 2;
	int b = 3;
	
	std::cout << "Before swap:	a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:	a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << "\n" << std::endl;
}

void	testIntEquality()
{
	printTitle("int - equality swap/min/max");

	int a = 42;
	int b = 42;
	
	std::cout << "Before swap:	a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:	a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << "\n" << std::endl;
}

void	testString()
{
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap:	c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap:	c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << "\n" << std::endl;
}

void	testFloatBasics()
{
	printTitle("float - basic swap/min/max");

	float a = 42.42f;
	float b = -42.42;
	
	std::cout << "Before swap:	a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:	a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << "\n" << std::endl;
}

int	main(void)
{
	testIntBasics();
	testIntEquality();
	testString();
	testFloatBasics();
	return (0);
}
