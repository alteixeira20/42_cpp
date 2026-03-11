/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:56:43 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:51:03 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

/* Default Constructor */
AForm::AForm()
	: _name("default"), _gradeToSign(42), _gradeToExecute(42), _isSigned(false)
{ 
}

/* Personalized Constructor */
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_isSigned(false)
{
	if (_gradeToSign < GRADE_HIGHEST || _gradeToExecute < GRADE_HIGHEST)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > GRADE_LOWEST || _gradeToExecute > GRADE_LOWEST)
		throw AForm::GradeTooLowException();
}

/* Copy Constructor */
AForm::AForm(const AForm &other)
	: _name(other._name),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), 
	_isSigned(other._isSigned)
{
}

/* Destructor */
AForm::~AForm(void)
{
}

/* Accessors */
const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/* Actions */
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

/* Equal Operator Overload */
AForm	&AForm::operator=(const AForm &form)
{
	if (this != &form)
		_isSigned = form._isSigned;
	return (*this);
}

/* Insertion Operator Overload */
std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	os << "AFORM:" << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	os << "Signature Status: ";
	if (form.isSigned())
		os << "true" << std::endl;
	else
		os << "false" << std::endl;
	return (os);
}

/* Exceptions */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}
