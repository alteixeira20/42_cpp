/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:22:07 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 15:26:38 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class	Bureaucrat;

class	Form
{
	public:
		/* Orthodox Canonical Form */
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();

		Form(const Form &other);
		Form& operator=(const Form &other);

		/* Accessors */
		const std::string	getName() const;
		bool			isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		
		/* Signs the form if the bureaucrat's grade is high enough */
		void			beSigned(const Bureaucrat &bureaucrat);

		/* Exceptions */
		class	GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
	private:
		/* Immutable identity and requeriments */
		const std::string	_name;
		const int		_gradeToSign;
		const int		_gradeToExecute;

		/* Mutable state */
		bool			_isSigned;

		/* Grade Limits */
		static const int	GRADE_HIGHEST = 1;
		static const int	GRADE_LOWEST = 150;
};

/* Stream insertion operator used for readable printing */
std::ostream&	operator<<(std::ostream &os, const Form &form);

#endif
