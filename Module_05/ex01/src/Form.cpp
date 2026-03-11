/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:56:43 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:50:30 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

/* Default Constructor */
Form::Form()
	: _name("default"), _gradeToSign(42), _gradeToExecute(42), _isSigned(false)
{ 
}

/* Personalized Constructor */
Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_isSigned(false)
{
	if (_gradeToSign < GRADE_HIGHEST || _gradeToExecute < GRADE_HIGHEST)
		throw Form::GradeTooHighException();
	if (_gradeToSign > GRADE_LOWEST || _gradeToExecute > GRADE_LOWEST)
		throw Form::GradeTooLowException();
}

/* Copy Constructor */
Form::Form(const Form &other)
	: _name(other._name),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), 
	_isSigned(other._isSigned)
{
}

/* Destructor */
Form::~Form(void)
{
}

/* Accessors */
const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/* Action */
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	
	this->_isSigned = true;
}

/* Equal Operator Overload */
Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		_isSigned = form._isSigned;
	return (*this);
}

/* Insertion Operator Overload */
std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "FORM:" << std::endl;
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
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
