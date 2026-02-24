/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:51:01 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 17:53:38 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <exception>

class	AForm;

class	Intern
{
	public:
		Intern();
		~Intern();
		
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

		AForm*	makeForm(const std::string &formName, const std::string &target) const;
		class	FormNotFoundException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
