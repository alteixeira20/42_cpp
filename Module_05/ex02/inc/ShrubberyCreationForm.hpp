/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:44:32 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:51:17 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
	protected:
		void	executeAction(void) const;

	private:
		std::string	_target;
};

#endif
