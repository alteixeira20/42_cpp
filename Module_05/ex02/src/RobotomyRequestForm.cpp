/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:31:25 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 16:44:16 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* Default Constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

/* Copy Constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target)
{
}

/* Copy Assignment Operator */
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

/* Execute Action */
void	RobotomyRequestForm::executeAction(void) const
{
	int		r;
	static bool	seeded = false;

	if (seeded == false)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	std::cout << "* drilling noises *" << std::endl;
	r = std::rand() % 2;
	if (r)
		std::cout << this->_target
			<< " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target
			<< " robotomy failed." << std::endl;
}
