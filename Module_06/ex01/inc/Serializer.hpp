/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:59:28 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/09 14:08:31 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

struct	Data
{
	int	n;
};

class	Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer&	operator=(const Serializer &other);
		~Serializer();
};

#endif
