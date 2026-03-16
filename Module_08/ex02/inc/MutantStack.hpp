/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:19:18 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/15 23:42:26 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

# include <stack>

template <typename T>
class	MutantStack: public std::stack<T>
{
	public:
		// OCF
		MutantStack(): std::stack<T>()
		{
		}
		MutantStack(const MutantStack &other): std::stack<T>(other)
		{
		}
		MutantStack	&operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack()
		{
		}

		typedef typename std::stack<T>::container_type::iterator		iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::const_iterator		const_iterator;
		const_iterator begin() const
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
};

#endif
