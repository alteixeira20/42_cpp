/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:12:17 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 17:30:19 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	printElem(T const &x)
{
	std::cout << x << std::endl;
}

void	incrementInt(int &x)
{
	x++;
}

void	toUpperChar(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
}

static void	printTitle(const std::string &title)
{
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	testIntArray()
{
	printTitle("int[] - print, mutate, print");

	int a[] = {1, 2, 3, 4};

	std::cout << "Original:" << std::endl;
	::iter(a, 4, printElem<int>);

	::iter(a, 4, incrementInt);

	std::cout << "After incrementInt:" << std::endl;
	::iter(a, 4, printElem<int>);
	std::cout << std::endl;
}

static void	testConstIntArray()
{
	printTitle("const int[] - print only");

	const int a[] = {100, 200, 300};

	::iter(a, 3, printElem<int>);
	//::iter(a, 3, incrementInt); // Shouldn't compile because const int isn't mutable
	std::cout << std::endl;
}

static void	testStringArray()
{
	printTitle("std::string[] - print");

	std::string s[] = {"h3ll0","big", "beautiful", "world"};

	::iter(s, 4, printElem<std::string>);
	std::cout << std::endl;
}

static void	testCharArray()
{
	printTitle("char [] - print, mutate, print");
	
	char	s[] = {'a', 'B', 'c', 'z'};

	std::cout << "Original:" << std::endl;
	::iter(s, 4, printElem<char>);

	::iter(s, 4, toUpperChar);

	std::cout << "After toUpperChar:" << std::endl;
	::iter(s, 4, printElem<char>);
}

int	main(void)
{
	testIntArray();
	testConstIntArray();
	testStringArray();
	testCharArray();

	return (0);
}
