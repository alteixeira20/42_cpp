/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:27:23 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/11 14:18:52 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);

		const std::string	getName() const;
		int			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

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
		static const int	GRADE_MIN = 150;
		static const int	GRADE_MAX = 1;
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
