/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:53:54 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 18:05:57 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

/* Factory Helpers: return heap-allocated AForm objects */
static AForm*	createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) const
{
	int	i;

	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm*	(*creators[3])(const std::string &) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};
	
	i = 0;
	while (i < 3)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](target));
		}
		i++;
	}
	std::cout << "Intern couldn't create " << formName
		<< " because form name does not exist." << std::endl;
	throw Intern::FormNotFoundException();
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Intern: form name not found");
}
