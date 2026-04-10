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
#include <cstdlib>	// std::strtol
#include <cerrno>	// errno
#include <ctime>	// std::clouck, CLOCKS_PER_SEC
#include <climits>	// INT_MAX
#include <cctype>	// std::is_digit
#include <iomanip>	// std::setprecision
#include <sys/time.h>	// gettimeofday

/* Local Helpers */

static double	getTimeMicros(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (static_cast<double>(ts.tv_sec) * 1000000.0
		+ static_cast<double>(ts.tv_nsec) / 1000.0);
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

/* Ford-Johnson Primitives */
static void	nextJacobsthal(std::size_t &j0, std::size_t &j1)
{
	std::size_t	next;

	// Compute next value from the two previous ones
	next = j1 + 2 * j0;
	j0 = j1;
	j1 = next;
}

template <typename Container>
static void	binaryInsert(Container &chain, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = static_cast<int>(chain.size());
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

/*
 * Builds the Jacobsthal insertion order for n elements.
 * Index 0 goes first, then groups are processed in descending order
 * within each Jacobsthal interval — minimises binary search range.
 */
static void	buildJacobsthalOrder(std::vector<std::size_t> &order, std::size_t n)
{
	std::size_t	j0;
	std::size_t	j1;
	std::size_t	limit;
	std::size_t	i;

	order.clear();
	if (n == 0)
		return ;
	order.push_back(0);
	j0 = 1;
	j1 = 3;
	while (j0 < n)
	{
		limit = j1;
		if (limit > n)
			limit = n;
		i = limit;
		while (i > j0)
		{
			i--;
			order.push_back(i);
		}
		nextJacobsthal(j0, j1);
	}
}

/*
 * Inserts all pending elements into chain using Jacobsthal order.
 * Elements not covered by Jacobsthal groups are appended at the end.
 */
template <typename Chain, typename Pending>
static void	insertPending(Chain &chain, const Pending &pending)
{
	std::vector<std::size_t>	order;
	std::vector<bool>		inserted;
	std::size_t			i;
	std::size_t			idx;

	buildJacobsthalOrder(order, pending.size());
	inserted.assign(pending.size(), false);
	i = 0;
	while (i < order.size())
	{
		idx = order[i];
		if (!inserted[idx])
		{
			binaryInsert(chain, pending[idx]);
			inserted[idx] = true;
		}
		i++;
	}
	i = 0;
	while (i < pending.size())
	{
		if (!inserted[i])
			binaryInsert(chain, pending[i]);
		i++;
	}
}

/*
 * Splits input into smalls (a) and bigs (b) in lockstep pairs.
 * If input is odd, the last element is saved as straggler.
 */
template <typename Container>
static void	splitPairs(const Container &input,
			Container &a,
			Container &b,
			bool &hasStraggler,
			int &straggler)
{
	std::size_t	i;

	a.clear();
	b.clear();
	hasStraggler = false;
	straggler = 0;
	if (input.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = input.back();
	}
	i = 0;
	while (i + 1 < input.size())
	{
		if (input[i] < input[i + 1])
		{
			a.push_back(input[i]);
			b.push_back(input[i + 1]);
		}
		else
		{
			a.push_back(input[i + 1]);
			b.push_back(input[i]);
		}
		i += 2;
	}
}

/* Ford-Johnson Vector Helpers */

/* Copies sorted bigs into chain — starting point for insertion */
static void	buildMainChainVector(std::vector<int> &chain,
			const std::vector<int> &b)
{
	std::size_t	i;

	chain.clear();
	i = 0;
	while (i < b.size())
	{
		chain.push_back(b[i]);
		i++;
	}
}

/* Collects all smalls and straggler into pending for insertion */
static void	buildPendingVector(std::vector<int> &pending,
			const std::vector<int> &a,
			bool hasStraggler,
			int straggler)
{
	std::size_t	i;

	pending.clear();
	i = 0;
	while (i < a.size())
	{
		pending.push_back(a[i]);
		i++;
	}
	if (hasStraggler)
		pending.push_back(straggler);
}

static void	fordJohnsonSortVector(std::vector<int> &v)
{
	std::vector<int>	a;
	std::vector<int>	b;
	std::vector<int>	chain;
	std::vector<int>	pending;
	bool			hasStraggler;
	int			straggler;

	if (v.size() <= 1)
		return ;
	splitPairs(v, a, b, hasStraggler, straggler);
	fordJohnsonSortVector(b);        /* recursively sort bigs */
	buildMainChainVector(chain, b);  /* chain = sorted bigs */
	buildPendingVector(pending, a, hasStraggler, straggler);
	insertPending(chain, pending);   /* merge smalls into chain */
	v.swap(chain);
}

/* Ford-Johnson Deque Helpers */

/* Copies sorted bigs into chain — starting point for insertion */
static void	buildMainChainDeque(std::deque<int> &chain,
			const std::deque<int> &b)
{
	std::size_t	i;

	chain.clear();
	i = 0;
	while (i < b.size())
	{
		chain.push_back(b[i]);
		i++;
	}
}

/* Collects all smalls and straggler into pending for insertion */
static void	buildPendingDeque(std::deque<int> &pending,
			const std::deque<int> &a,
			bool hasStraggler,
			int straggler)
{
	std::size_t	i;

	pending.clear();
	i = 0;
	while (i < a.size())
	{
		pending.push_back(a[i]);
		i++;
	}
	if (hasStraggler)
		pending.push_back(straggler);
}

static void	fordJohnsonSortDeque(std::deque<int> &d)
{
	std::deque<int>	a;
	std::deque<int>	b;
	std::deque<int>	chain;
	std::deque<int>	pending;
	bool		hasStraggler;
	int		straggler;

	if (d.size() <= 1)
		return ;
	splitPairs(d, a, b, hasStraggler, straggler);
	fordJohnsonSortDeque(b);
	// Chain starts with sorted bigs only
	buildMainChainDeque(chain, b);
	// All smalls go into pending — no free prepend since pairing is lost
	buildPendingDeque(pending, a, hasStraggler, straggler);
	insertPending(chain, pending);
	d.swap(chain);
}

static void	fillVector(int argc, char **argv, std::vector<int> &v)
{
	int	i;
	int	val;

	v.clear();
	i = 1;
	while (i < argc)
	{
		val = validateAndParse(argv[i]);
		v.push_back(val);
		i++;
	}
	if (v.empty())
		throw PmergeMe::Error("Error");
}

static void	fillDeque(int argc, char **argv, std::deque<int> &d)
{
	int	i;
	int	val;

	d.clear();
	i = 1;
	while (i < argc)
	{
		val = validateAndParse(argv[i]);
		d.push_back(val);
		i++;
	}
	if (d.empty())
		throw PmergeMe::Error("Error");
}

/* Core Logic */
void	PmergeMe::run(int argc, char **argv)
{
	double	start;
	double	end;
	double	vecMicros;
	double	deqMicros;

	if (argc < 2)
		throw PmergeMe::Error("Error");

	_vec.clear();
	_deq.clear();
	fillVector(argc, argv, _vec);
	printSequence("Before: ", _vec);
	_vec.clear();

	// Vector Sorting Timer
	start = getTimeMicros();
	fillVector(argc, argv, _vec);
	fordJohnsonSortVector(_vec);
	end = getTimeMicros();
	vecMicros = end - start;

	// Deque Sorting Timer
	start = getTimeMicros();
	fillDeque(argc, argv, _deq);
	fordJohnsonSortDeque(_deq);
	end = getTimeMicros();
	deqMicros = end - start;

	// Output
	printSequence("After: ", _vec);

	std::cout << std::fixed << std::setprecision(3);

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vecMicros << " us" << std::endl;

	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << deqMicros << " us" << std::endl;
}
