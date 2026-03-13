/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:55:28 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 17:12:12 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T *arr, size_t len, F f)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T, typename F>
void	iter(T const *arr, size_t len, F f)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

#endif
