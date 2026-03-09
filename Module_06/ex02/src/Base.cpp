/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:57:50 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/09 15:00:07 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base &other)
{
	(void)other;
}

Base	&Base::operator=(const Base &other)
{
	(void)other;
	return (*this);
}

Base::~Base()
{
}
