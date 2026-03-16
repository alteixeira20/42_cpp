/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:29:58 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 22:30:39 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

static void	printTitle(const char *title)
{
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	printSpans(const Span &sp)
{
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
}



static void	testBasics()
{
	printTitle("Test - Basic example (5 numbers)");
	try
	{
		Span	sp(5);
		sp.addNumber(42);
		sp.addNumber(55);
		sp.addNumber(0);
		sp.addNumber(101);
		sp.addNumber(75);
		printSpans(sp);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void	testDuplicates()
{
	printTitle("Test - Duplicates (expected 0 spans)");
	try
	{
		Span	sp(2);
		sp.addNumber(42);
		sp.addNumber(42);
		printSpans(sp);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void	testNegatives()
{
	printTitle("Test - Negative numbers");
	try
	{
		Span	sp(3);
		sp.addNumber(-42);
		sp.addNumber(42);
		sp.addNumber(0);
		printSpans(sp);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void	testExceptions()
{
	printTitle("Test - Exceptions");
	try
	{
		Span	sp(5);

		std::cout << " Empty span using shortestSpan:" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "	Exception: " << e.what() << std::endl;
	}

	try
	{
		Span	sp(5);

		sp.addNumber(42);

		std::cout << " One element using longestSpan:" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "	Exception: " << e.what() << std::endl;
	}

	try
	{
		Span	sp(2);
		
		sp.addNumber(42);
		sp.addNumber(4242);
		std::cout << " Adding a number to exceed capacity:" << std::endl;
		sp.addNumber(424242);
	}
	catch (const std::exception &e)
	{
		std::cout << "	Exception: " << e.what() << std::endl;
	}
}

static void	testBigRange()
{
	printTitle("Test - Add multiple numbers using addNumber");
	try
	{
		const unsigned int	N = 10000;
		Span	sp(N);
		std::vector<int>	v;
		unsigned int		i;
		
		v.reserve(N);
		i = 0;
		while (i < N)
		{
			v.push_back(static_cast<int>(i));
			i++;
		}
		sp.addNumber(v.begin(), v.end());
		printSpans(sp);
		
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void	testExtremellyBigRange()
{
	printTitle("Test - Add multiple numbers using addNumber");
	try
	{
		const unsigned int	N = 100000;
		Span	sp(N);
		std::vector<int>	v;
		unsigned int		i;
		
		v.reserve(N);
		i = 0;
		while (i < N)
		{
			v.push_back(static_cast<int>(i));
			i++;
		}
		sp.addNumber(v.begin(), v.end());
		printSpans(sp);
		
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	testDuplicates();
	std::cout << std::endl;
	testBasics();
	std::cout << std::endl;
	testNegatives();
	std::cout << std::endl;
	testExceptions();
	std::cout << std::endl;
	testBigRange();
	std::cout << std::endl;
	testExtremellyBigRange();

	return (0);
}
