/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:46:35 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/10 17:55:51 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array():
	_data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n):
	_data(NULL), _size(n)
{
	if (_size == 0)
		return ;
	_data = new T[_size]();
}

template <typename T>
Array<T>::Array(Array const &other):
	_data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	size_t	i;

	if (this == &other)
		return (*this);
	delete [] _data;
	_data = NULL;
	_size = other._size;

	if (_size == 0)
		return (*this);
	
	_data = new T[_size]();
	i = 0;
	while (i < _size)
	{
		_data[i] = other._data[i];
		i++;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
const char	*Array<T>::OutOfBounds::what() const throw()
{
	return ("Array: index out of bounds");
}

template <typename T>
T	&Array<T>::operator[](size_t idx)
{
	if (idx >= _size)
		throw OutOfBounds();
	return (_data[idx]);
}

template <typename T>
T	const &Array<T>::operator[](size_t idx) const
{
	if (idx >= _size)
		throw OutOfBounds();
	return (_data[idx]);
}

#endif
