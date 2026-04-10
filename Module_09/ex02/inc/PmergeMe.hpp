/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:17:09 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 19:27:18 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <stdexcept>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);
		class	Error: public std::runtime_error
		{
			public:
				Error(const std::string &msg): std::runtime_error(msg) {}
		};
		struct	Pair
		{
			int	small;
			int	big;
		};
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

};

#endif
