/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:32:42 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 16:39:08 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	else
		return (b);

}

#endif
