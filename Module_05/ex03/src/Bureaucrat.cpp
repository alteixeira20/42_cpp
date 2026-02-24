/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:41:38 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 16:16:37 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include <iostream>

/** Default Constructor **/
Bureaucrat::Bureaucrat(): _name("default"), _grade(42)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

/** Personalized Constructor **/
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (this->_grade < GRADE_HIGHEST)
		throw GradeTooHighException();
	if (this->_grade > GRADE_LOWEST)
		throw GradeTooLowException();
}

/** Copy Constructor **/
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
}

/** Destructor **/
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << _name
		<< " with grade " << _grade << std::endl;
}

/** Copy Assignment operator **/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

/** Getters **/
const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/** Changers **/
void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= GRADE_HIGHEST)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= GRADE_LOWEST)
		throw GradeTooLowException();
	this->_grade++;
}

/* Actions */
void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName()
			<< std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed "
			<< form.getName() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << this->getName() << " couldn't execute "
			<< form.getName() << " because " << e.what()
			<< "." << std::endl;
	}
}

/** Exceptions **/
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

/** Overload stream insertion Operator **/
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (os);
}
