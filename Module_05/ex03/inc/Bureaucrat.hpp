/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:27:23 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 16:12:44 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class	AForm;

class	Bureaucrat
{
	public:
		/* Orthodox Canonical Form */
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);

		/* Accessors */
		const std::string	getName() const;
		int			getGrade() const;
		
		/* Grade Modifiers */
		void			incrementGrade();
		void			decrementGrade();

		/* Actions */
		void			signForm(AForm &form);
		void			executeForm(AForm const &form) const;

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
		const std::string	_name;
		int			_grade;
		static const int	GRADE_HIGHEST = 1;
		static const int	GRADE_LOWEST = 150;
};

/* Stream insertion operator used for readable printing */
std::ostream&	operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
