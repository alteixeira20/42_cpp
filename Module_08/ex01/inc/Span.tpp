/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:06:03 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 21:27:01 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include <iterator>

template <typename InputIt>
void	Span::addNumber(InputIt first, InputIt last)
{
	typename std::iterator_traits<InputIt>::difference_type	count;
	unsigned int						add;
	unsigned int						current;

	count = std::distance(first, last);
	if (count <= 0)
		return ;
	add = static_cast<unsigned int>(count);
	current = static_cast<unsigned int>(_numbers.size());

	if (current + add > _capacity)
		throw NoMoreSpace();
	_numbers.insert(_numbers.end(), first, last);
}

#endif
