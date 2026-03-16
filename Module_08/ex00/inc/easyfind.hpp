/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:16:40 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 19:44:52 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T& container, int value)
{
	typename T::const_iterator	nbr;
	typename T::const_iterator	end;

	nbr = container.begin();
	end = container.end();

	while (nbr != end)
	{
		if (*nbr == value)
			return (nbr);
		++nbr;
	}
	return (end);
}

#endif
