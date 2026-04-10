/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:28:21 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/10 09:23:20 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>	// std::cout, std::cerr
#include <sstream>	// std::istringstream
#include <cstdlib>	// std::strtol
#include <cerrno>	// errno
#include <ctime>	// std::clouck, CLOCKS_PER_SEC
#include <climits>	// INT_MAX
#include <cctype>	// std::is_digit
#include <iomanip>	// std::setprecision
#include <algorithm>	// std::lower_bound, std::find

/* Local Helpers */

static long	clockToMicros(std::clock_t ticks)
{
	long	microseconds; // microseconds = ticks * 1e6 / CLOCKS_PER_SEC
	
	microseconds = ticks * 1000000.L / CLOCKS_PER_SEC;

	return (microseconds);
}

static bool	isAllDigits(const std::string &str)
{
	std::string::size_type	i;

	if (str.empty())
		return (false);
	i = 0;
	while (i < str.size())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	return (true);
}

static int	validateAndParse(const std::string &str)
{
	char	*end;
	long	val;

	if (!isAllDigits(str))
		throw PmergeMe::Error("Error");

	errno = 0;
	end = NULL;
	val = std::strtol(str.c_str(), &end, 10);
	if (errno != 0 || end == str.c_str() || *end != '\0')
		throw PmergeMe::Error("Error");
	if (val <= 0 || val > INT_MAX)
		throw PmergeMe::Error("Error");

	return (static_cast<int>(val));
}

static void	fillContainers(int argc, char **argv, std::vector<int> &v, std::deque<int> &d)
{
	int	i;
	int	val;

	i = 1;
	while (i < argc)
	{
		val = validateAndParse(argv[i]);
		v.push_back(val);
		d.push_back(val);
		i++;
	}
	if (v.empty())
		throw PmergeMe::Error("Error");
}

static void	printSequence(const std::string &label, const std::vector<int> &v)
{
	std::size_t	i;

	std::cout << label;
	i = 0;
	while (i < v.size())
	{
		std::cout << v[i];
		if (i + 1 < v.size())
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

/* OCF */

PmergeMe::PmergeMe(): _vec(), _deq()
{
}

PmergeMe::PmergeMe(const PmergeMe &other): _vec(other._vec), _deq(other._deq)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

/* Ford-Johnson Algorithm Helpers */
static void	nextJacobsthal(std::size_t &j0, std::size_t &j1)
{
	std::size_t	next;

	// Compute next value from the two previous ones
	next = j1 + 2 * j0;
	j0 = j1;
	j1 = next;
}

static void	insertGroup(std::size_t from, std::size_t to,
			std::vector<std::size_t> &order, std::vector<bool> &used)
{
	std::size_t	i;

	i = to;
	while (i >= from)
	{
		// Only add index if not already scheduled
		if (!used[i])
		{
			order.push_back(i);
			used[i] = true;
		}
		// Guard against size_t underflow wrapping around on i == 0
		if (i == 0)
			break ;
		i--;
	}
}

static std::vector<std::size_t>	buildJacobsthalOrder(std::size_t n)
{
	std::vector<std::size_t>	order;
	std::vector<bool>		used(n, false);
	std::size_t			j0;
	std::size_t			j1;
	std::size_t			groupEnd;


	if (n == 0)
		return (order);

	order.reserve(n);

	// Index 0 is always inserted first — its small costs 0 comparisons
	order.push_back(0);
	used[0] = true;

	// J(2)=1, J(3)=3 — first real group boundary
	j0 = 1; // J(2)
	j1 = 3; // J(3)
	
	// Each iteration handles one Jacobsthal group [j0..j1-1]
	while (j0 < n)
	{
		if (j1 < n)
			groupEnd = j1;
		else
			groupEnd = n - 1;
		insertGroup(j0, groupEnd, order, used);
		nextJacobsthal(j0, j1);
	}

	// Safety net: append any indices not yet covered
	for (std::size_t i = 1; i < n; ++i)
		if (!used[i])
			order.push_back(i);

	return (order);
}

template <typename Chain>
static void	insertSmallBounded(Chain &chain, int small, int bound)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = bound; // bound is already an index, not a value
	// Binary search only up to the paired big's position
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (small < chain[mid])
			right = mid;
		else
			left = mid + 1;
	}
	chain.insert(chain.begin() + left, small);
}

template <typename Chain>
static void	insertFull(Chain &chain, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = static_cast<int>(chain.size());
	// Binary search for correct sorted position
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < chain[mid])
			right = mid;
		else
			left = mid + 1;
	}
	chain.insert(chain.begin() + left, value);
}
/* Sorting using Ford-Johnson (merge-insertion) for vector & deque */

static void	fordJohnsonSortVector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return ;

	// 1) Split into smalls (a) and bigs (b), save straggler if odd
	std::vector<int>	a;
	std::vector<int>	b;
	bool			hasStraggler;
	int			straggler;

	a.reserve(v.size() / 2);
	b.reserve(v.size() / 2);
	hasStraggler = (v.size() % 2 != 0);
	straggler = hasStraggler ? v.back() : 0;

	for (std::size_t i = 0; i + 1 < v.size(); i += 2)
	{
		// Always push smaller to a, larger to b
		if (v[i] < v[i + 1])
		{
			a.push_back(v[i]);
			b.push_back(v[i + 1]);
		}
		else
		{
			a.push_back(v[i + 1]);
			b.push_back(v[i]);
		}
	}

	// 2) Recursively sort bigs
	fordJohnsonSortVector(b);

	// 3) Build chain: a[0] first (free insert), then all sorted bigs
	std::vector<int>	chain;
	std::vector<int>	pending;

	chain.reserve(v.size());
	pending.reserve(a.size());

	// a[0] <= b[0] guaranteed, prepend costs 0 comparisons
	chain.push_back(a[0]);
	for (std::size_t i = 0; i < b.size(); ++i)
		chain.push_back(b[i]);

	// 4) Build pending: a[1..n], then straggler if odd
	for (std::size_t i = 1; i < a.size(); ++i)
		pending.push_back(a[i]);
	if (hasStraggler)
		pending.push_back(straggler);

	// 5) Insert pending into chain in Jacobsthal order
	std::vector<std::size_t>	order = buildJacobsthalOrder(pending.size());
	std::size_t			k;
	std::size_t			idx;

	k = 0;
	while (k < order.size())
	{
		idx = order[k];
		if (idx < pending.size())
			insertFull(chain, pending[idx]);
		k++;
	}

	// 6) Write sorted result back
	v.swap(chain);
}

static void	fordJohnsonSortDeque(std::deque<int> &d)
{
	if (d.size() <= 1)
		return ;

	// 1) Split into smalls (a) and bigs (b), save straggler if odd
	std::deque<int>	a;
	std::deque<int>	b;
	bool		hasStraggler;
	int		straggler;

	hasStraggler = (d.size() % 2 != 0);
	straggler = hasStraggler ? d.back() : 0;

	for (std::size_t i = 0; i + 1 < d.size(); i += 2)
	{
		// Always push smaller to a, larger to b
		if (d[i] < d[i + 1])
		{
			a.push_back(d[i]);
			b.push_back(d[i + 1]);
		}
		else
		{
			a.push_back(d[i + 1]);
			b.push_back(d[i]);
		}
	}

	// 2) Recursively sort bigs
	fordJohnsonSortDeque(b);

	// 3) Build chain: a[0] first (free insert), then all sorted bigs
	std::deque<int>	chain;
	std::deque<int>	pending;

	// a[0] <= b[0] guaranteed, prepend costs 0 comparisons
	chain.push_back(a[0]);
	for (std::size_t i = 0; i < b.size(); ++i)
		chain.push_back(b[i]);

	// 4) Build pending: a[1..n], then straggler if odd
	for (std::size_t i = 1; i < a.size(); ++i)
		pending.push_back(a[i]);
	if (hasStraggler)
		pending.push_back(straggler);

	// 5) Insert pending into chain in Jacobsthal order
	std::vector<std::size_t>	order = buildJacobsthalOrder(pending.size());
	std::size_t			k;
	std::size_t			idx;

	k = 0;
	while (k < order.size())
	{
		idx = order[k];
		if (idx < pending.size())
			insertFull(chain, pending[idx]);
		k++;
	}

	// 6) Write sorted result back
	d.swap(chain);
}

/* Core Logic */
void	PmergeMe::run(int argc, char **argv)
{
	std::clock_t	start;
	std::clock_t	end;
	long		vecMicros;
	long		deqMicros;

	if (argc < 2)
		throw PmergeMe::Error("Error");

	_vec.clear();
	_deq.clear();
	fillContainers(argc, argv, _vec, _deq);

	printSequence("Before: ", _vec);

	// Vector Sorting Timer
	start = std::clock();
	fordJohnsonSortVector(_vec);
	end = std::clock();
	vecMicros = clockToMicros(end - start);

	// Deque Sorting Timer
	start = std::clock();
	fordJohnsonSortDeque(_deq);
	end = std::clock();
	deqMicros = clockToMicros(end - start);

	// Output
	printSequence("After: ", _vec);
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector: " << vecMicros << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque: " << deqMicros << " us" << std::endl;
}
