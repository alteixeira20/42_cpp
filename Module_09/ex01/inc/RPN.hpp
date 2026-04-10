/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:16:33 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 16:20:54 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class	RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		long	evaluate(const std::string &expr) const;

		class	Error: public std::runtime_error
		{
			public:
				Error(const std::string &msg): std::runtime_error(msg) {}
		};
	private:
};

#endif
