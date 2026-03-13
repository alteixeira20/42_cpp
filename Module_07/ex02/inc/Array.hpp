/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:40:24 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 17:45:55 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array	&operator=(Array const &other);
		~Array();

		size_t	size(void) const;
		T	&operator[](size_t idx);
		T	const &operator[](size_t idx) const;

		class	OutOfBounds: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		T	*_data;
		size_t	_size;
};

# include "Array.tpp"

#endif
