/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:35:25 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 21:30:29 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <ostream>

class	Span
{
	public:
		// OCF
		Span();
		Span(Span const &other);
		Span	&operator=(Span const &other);
		~Span();

		// Custom
		explicit	Span(unsigned int n);
		void	addNumber(int nbr);

		template <typename InputIt>
		void	addNumber(InputIt first, InputIt last);

		unsigned int	getCapacity() const;

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		// Exceptions
		class	NoMoreSpace: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	NoSpan: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		unsigned int		_capacity;
		std::vector<int>	_numbers;
};

# include "Span.tpp"

#endif
