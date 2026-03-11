/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:22:07 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:51:36 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <ostream>
#include <exception>

class	Bureaucrat;

class	AForm
{
	public:
		/* Orthodox Canonical Form */
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		/* Accessors */
		const std::string	getName() const;
		bool			isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		
		/* Actions */
		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;

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
		
		class	FormNotSignedException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
	protected:
		AForm();
		/* Force derived classes to implement the proper behaviour */
		virtual void	executeAction() const = 0;
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
std::ostream&	operator<<(std::ostream &os, const AForm &form);

#endif
