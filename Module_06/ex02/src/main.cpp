/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:10:11 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/09 15:21:04 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void	runOnce(int i)
{
	Base	*p;

	std::cout << "--- test #" << i << " ---" << std::endl;

	p = generate();
	std::cout << "identify(Base*): ";
	identify(p);

	std::cout << "identify(Base&): ";
	identify(*p);

	delete p;
	std::cout << std::endl;
}

static void	testNULL()
{
	std::cout << "--- test NULL pointer ---" << std::endl;
	std::cout << "identify(Base*): ";
	identify(static_cast<Base *>(NULL));
	std::cout << std::endl;
}

static void	testUnknown()
{
	Base	base;

	std::cout << "--- Base object (should be Unknown) ---" << std::endl;
	std::cout << "identify(Base*): ";
	identify(&base);

	std::cout << "identify(Base&): ";
	identify(base);
	std::cout << std::endl;
}

int	main(void)
{
	int	i;

	std::srand(std::time(NULL));
	
	i = 1;
	while (i <= 10)
	{
		runOnce(i);
		i++;
	}

	testNULL();
	testUnknown();
	return (0);
}
