/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:01:32 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/09 15:08:29 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base	*generate(void)
{
	int	r;

	r = std::rand() % 3;
	if (r == 0)
	{
		std::cout << "[generate] A" << std::endl;
		return (new A);
	}
	if (r == 1)
	{
		std::cout << "[generate] B" << std::endl;
		return (new B);
	}
	std::cout << "[generate] C" << std::endl;
	return (new C);
}

void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	std::cout << "Unknown" << std::endl;
}
