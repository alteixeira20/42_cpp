/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:27:53 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:51:43 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
	protected:
		void	executeAction(void) const;

	private:
		std::string	_target;
};

#endif
