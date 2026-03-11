/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:47:44 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:52:16 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <exception>

/* Default Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("shrubbery creation", 145, 137), _target(target)
{
}

/* Copy Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), _target(copy._target)
{
}

/* Copy Assignment Operator */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

/* Execute Action */
void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	out;
	std::string	filename;

	filename = this->_target + "_shrubbery";
	out.open(filename.c_str());
	if (out.is_open() == false)
		throw std::exception();

	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~         ~~\\" << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;

	out.close();
}
