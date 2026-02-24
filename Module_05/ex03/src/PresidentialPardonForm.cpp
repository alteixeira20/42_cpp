/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:21:38 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 16:26:34 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

/* Default Constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

/* Copy Constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target)
{
}

/* Copy Assignment Operator */
PresidentialPardonForm	&PresidentialPardonForm::operator=(
	const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/* Execute Action */
void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
