/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:45:04 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 20:06:57 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include "easyfind.hpp"

template <typename T>
static void	printContainer(const T &c)
{
	std::cout << "[ ";
	std::copy(c.begin(), c.end(),
	   std::ostream_iterator<typename T::value_type>(std::cout, " "));
	std::cout << "]" << std::endl;
}

template <typename T>
static void	printSearchResult(const T &c, int value)
{
	typename T::const_iterator	it;

	it = easyfind(c, value);
	std::cout << "search = " << value << std::endl;
	if (it == c.end())
		std::cout << "result: not found (iterator == end)" << std::endl;
	else
		std::cout << "result: index = " << std::distance(c.begin(), it)
			<< " | value = " << *it << std::endl;
}

template <typename T>
static void	runTest(const char *title, const T &c, int value)
{
	std::cout << "=== " << title << " ===" << std::endl;
	std::cout << "container = ";
	printContainer(c);
	printSearchResult(c, value);
	std::cout << std::endl;
}

static void	testVector()
{
	{
		std::vector<int>	v;
		runTest("VECTOR: empty", v, 42);
	}
	{
		std::vector<int>	v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		runTest("VECTOR: found (first)", v, 1);
	}
	{
		std::vector<int>	v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		runTest("VECTOR: found (middle)", v, 2);
	}
	{
		std::vector<int>	v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		runTest("VECTOR: found (last)", v, 3);
	}
	{
		std::vector<int>	v;
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		runTest("VECTOR: not found (non-empty)", v, 42);
	}
	{
		std::vector<int>	v;
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);
		v.push_back(7);
		runTest("VECTOR: duplicates (first occurrence)", v, 7);
	}
	{
		std::vector<int>	v;
		v.push_back(-42);
		v.push_back(0);
		v.push_back(42);
		runTest("VECTOR: negative value", v, -42);
	}
	{
		const std::vector<int>	v(5, 42);
		runTest("VECTOR: const vector", v, 42);
	}
}

static void	testList()
{
	{
		std::list<int>	l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		runTest("LIST: found", l, 20);
	}
	{
		std::list<int>	l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		runTest("LIST: not found", l, 42);
	}
}

int	main(void)
{
	testVector();
	testList();
	return (0);
}
