/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:01:34 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 22:29:27 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <algorithm>

Span::Span():
	_capacity(0), _numbers()
{
}

Span::Span(unsigned int	n):
	_capacity(n), _numbers()
{
	_numbers.reserve(n);
}

Span::~Span()
{
}

Span::Span(const Span &other):
	_capacity(other._capacity), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (_numbers.size() >= _capacity)
		throw NoMoreSpace();
	_numbers.push_back(nbr);
}

unsigned int	Span::getCapacity() const
{
	return (_capacity);
}

unsigned int Span::longestSpan() const
{
	std::vector<int>::const_iterator	minIt;
	std::vector<int>::const_iterator	maxIt;
	int	span;

	if (_numbers.size() < 2)
		throw NoSpan();

	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	span = *maxIt - *minIt;

	return (static_cast<unsigned int>(span));
}

unsigned int Span::shortestSpan() const
{
	int				span;
	std::vector<int>::size_type	i;
	std::vector<int>		tmp;

	if (_numbers.size() < 2)
		throw NoSpan();
	
	tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	span = tmp[1] - tmp[0];
	i = 0;
	while (i + i < tmp.size())
	{

		if (span > tmp[i + 1] - tmp[i])
			span = tmp[i + 1] - tmp[i];
		i++;
	}
	return (static_cast<unsigned int>(span));
}

const char	*Span::NoMoreSpace::what() const throw()
{
	return ("The container reached it's capacity!");
}

const char	*Span::NoSpan::what() const throw()
{
	return ("No span was detected in the container!");
}
