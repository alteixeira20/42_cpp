/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:26:23 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 23:33:22 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

static void	printTitle(const char *title)
{
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	printIter(const MutantStack<int> &ms)
{
	MutantStack<int>::const_iterator it = ms.begin();
	MutantStack<int>::const_iterator end = ms.end();

	std::cout << "Iterate (begin -> end):" << std::endl;

	while (it != end)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	printReverseIter(const MutantStack<int> &ms)
{
	MutantStack<int>::const_reverse_iterator	it;
	MutantStack<int>::const_reverse_iterator	end_it;

	it = ms.rbegin();
	end_it = ms.rend();
	std::cout << "Iterate (rbegin -> rend):" << std::endl;

	while (it != end_it)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static MutantStack<int>	buildSample()
{
	MutantStack<int>	ms;

	ms.push(5);
	ms.push(42);
	ms.pop();
	ms.push(3);
	ms.push(5);
	ms.push(0);

	return (ms);
}

static void	testSubjectExample()
{
	MutantStack<int>	ms;
	MutantStack<int>::iterator it;
	MutantStack<int>::iterator end_it;

	printTitle("Subject example (push, pop, top, size + iterator)");
	
	ms.push(5);
	ms.push(17);
	
	std::cout << "top() = " << ms.top() << std::endl;
	ms.pop();
	std::cout << "size() = " << ms.size() << std::endl;

	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);

	it = ms.begin();
	end_it = ms.end();
	++it;
	--it;
	
	std::cout << "Iterate (begin -> end):" << std::endl;
	while (it != end_it)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(ms);
	(void)s;
}

static void	testCopyAndConst()
{
	printTitle("Copy + assign + const iteration");
	MutantStack<int>	a = buildSample();
	MutantStack<int>	b(a);
	MutantStack<int>	c;
	const MutantStack<int>	ca(a);

	c = a;

	std::cout << "Original:" << std::endl;
	printIter(a);

	std::cout << "Copy-constructed:" << std::endl;
	printIter(b);

	std::cout << "Assigned:" << std::endl;
	printIter(c);

	std::cout << "Const iteration:" << std::endl;
	printIter(ca);

}

static void	testReverse()
{
	printTitle("Reverse iteration");

	MutantStack<int> ms = buildSample();
	printReverseIter(ms);
}

int	main(void)
{
	testSubjectExample();
	std::cout << std::endl;
	testCopyAndConst();
	std::cout << std::endl;
	testReverse();

	return (0);
}
