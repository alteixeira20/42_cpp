<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/STL%20Containers-0A5F38?style=for-the-badge&logoColor=white" alt="STL Containers badge">
  <img src="https://img.shields.io/badge/Iterators-7C3AED?style=for-the-badge&logoColor=white" alt="Iterators badge">
  <img src="https://img.shields.io/badge/Template%20Functions-1D3557?style=for-the-badge&logoColor=white" alt="Template Functions badge">
  <img src="https://img.shields.io/badge/Container%20Adaptor-B23A48?style=for-the-badge&logoColor=white" alt="Container Adaptor badge">
</p>

<h1 align="center">Module 08 — Templated Containers, Iterators & Algorithms</h1>
<p align="center">Generic search over any STL container, span computation with bulk insertion, and a stack that finally lets you iterate over its elements.</p>

## Table of Contents
1. [At a Glance](#at-a-glance)
2. [Learning Objectives](#learning-objectives)
3. [Key Concepts to Review](#key-concepts-to-review)
4. [Exercises Overview](#exercises-overview)
5. [Implementation Notes per Exercise](#implementation-notes-per-exercise)
6. [Rules & Constraints](#rules--constraints)
7. [Approach & Tips](#approach--tips)
8. [What to Deliver](#what-to-deliver)
9. [Looking Ahead](#looking-ahead)

## At a Glance
> **Highlights:** STL containers and algorithms are now allowed — this module is about using them well alongside templates.
- `ex00` implements `easyfind`, a function template that searches any integer container by walking its iterators and returning one to the first match, or `end` if none is found.
- `ex01` builds `Span`, a class that stores up to `N` integers, computes the shortest and longest span between any two values, and accepts bulk insertion through a template member function that takes any pair of iterators.
- `ex02` creates `MutantStack`, a template class adaptor that inherits `std::stack<T>` and exposes the otherwise-hidden underlying container as a full iterator range, making the stack iterable without changing its stack semantics.

## Learning Objectives
> **Goal:** use STL containers and algorithms as tools, not obstacles, and understand the iterator model well enough to build on top of it.
- Write a function template that is agnostic to the specific container type and works through the iterator interface alone.
- Understand the difference between returning an iterator and throwing an exception when a search fails.
- Use `std::sort`, `std::min_element`, and `std::max_element` to compute results without manual reimplementation.
- Add a template member function to a non-template class using a separate `.tpp` file.
- Inherit from an STL adaptor class and expose its protected `c` member to unlock iteration.
- Expose all four iterator flavours — `iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator` — through a single header.

## Key Concepts to Review
> **Refresh before coding.**
- How iterators unify all STL containers behind a common interface: `begin()`, `end()`, `++`, `*`.
- `T::const_iterator` as a dependent type and why `typename` is required in front of it.
- `std::distance` and `std::iterator_traits<InputIt>::difference_type` for measuring iterator ranges.
- `std::stack` as a container adaptor: it wraps a `std::deque` by default and its elements live in the protected member `c`.
- Why inheriting from STL containers is generally discouraged, and why it is still valid here for a pedagogical adaptor exercise.
- The difference between `reserve()` (pre-allocate capacity) and `resize()` (change size) on `std::vector`.

## Exercises Overview
> **What this module builds in this repo.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` easyfind | Find the first occurrence of an integer in any container. | Function templates, iterators, container-agnostic search. |
| `ex01` Span | Store integers, enforce capacity, compute min and max span. | STL algorithms, template member functions, iterator-range insertion. |
| `ex02` MutantStack | Give `std::stack` full iterator support through inheritance. | Container adaptors, protected member access, iterator typedef exposure. |

## Implementation Notes per Exercise
- **ex00:** `easyfind` is a single function template in `easyfind.hpp`. It receives `const T&` and `int value`, declares two `T::const_iterator` variables for the current position and the end, then walks the range manually comparing `*nbr == value`. If a match is found the iterator is returned immediately; otherwise `end` is returned and the caller checks against `c.end()`. The test driver exercises `std::vector<int>` across eight scenarios — empty container, first/middle/last position, not found, duplicate values (returns first occurrence), negative values, and a const vector — plus two cases with `std::list<int>`.
  Run: `make -C ex00 && ./ex00/easyfind`

- **ex01:** `Span` is a concrete class backed by a `std::vector<int> _numbers` and a `unsigned int _capacity`. The constructor calls `_numbers.reserve(n)` to pre-allocate. Single-value `addNumber(int)` checks `_numbers.size() >= _capacity` and throws `Span::NoMoreSpace` before pushing. The range overload `addNumber(InputIt first, InputIt last)` lives in `Span.tpp` (included at the bottom of `Span.hpp`): it calls `std::distance` to count incoming elements, casts to `unsigned int`, checks that current size plus new count does not exceed capacity, then delegates to `_numbers.insert(_numbers.end(), first, last)`. `shortestSpan()` copies `_numbers` into a temporary vector, sorts it, and walks adjacent pairs to find the minimum consecutive gap. `longestSpan()` uses `std::max_element` and `std::min_element` directly on `_numbers`. Both throw `Span::NoSpan` when fewer than two elements are stored. The test driver covers duplicates (span of zero), a basic five-number case, negative numbers, three exception paths (empty span, one-element span, overflow on insert), and two bulk-insertion tests at 10 000 and 100 000 elements.
  Run: `make -C ex01 && ./ex01/span`

- **ex02:** `MutantStack<T>` inherits publicly from `std::stack<T>` and adds nothing to its push/pop/top/size semantics — all stack operations delegate to the base class. The only addition is four pairs of `begin`/`end` methods that forward to `this->c.begin()` and `this->c.end()` (and their reverse variants), where `c` is `std::stack`'s protected underlying container member. Four `typedef`s expose the iterator types: `iterator`, `const_iterator`, `reverse_iterator`, and `const_reverse_iterator`, all derived from `std::stack<T>::container_type`. The entire class is header-only in `MutantStack.hpp`. The test driver reproduces the exact subject example — `push`, `pop`, `top`, `size`, forward iteration — then tests copy construction, assignment, const iteration, and reverse iteration. It also verifies that a `MutantStack` can be sliced into a plain `std::stack<int>` without issue.
  Run: `make -C ex02 && ./ex02/MutantStack`

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compile with `c++ -Wall -Wextra -Werror`, still compatible with `-std=c++98`.
- Forbidden: `printf`, `malloc`, `free`, external libraries, `using namespace`, `friend`.
- STL containers and algorithms are now allowed — this is the first module where they are the expected tool.
- `Span` must follow Orthodox Canonical Form.
- `MutantStack` must not break standard stack behaviour; it only extends it.

## Approach & Tips
> **What matters during implementation.**
- In `ex00`, returning `end` instead of throwing is intentional: iterators are the STL's natural "not found" signal, and the caller decides what to do with that.
- In `ex01`, always check capacity before inserting — both for single and range insertions. The range overload must check the total count of incoming elements atomically before calling `insert`, not one by one.
- In `ex01`, `shortestSpan` needs the copy-sort approach because `std::sort` would mutate `_numbers` and change the object's observable state.
- In `ex02`, `this->c` is accessible because `MutantStack` is a subclass of `std::stack<T>` and `c` is declared `protected` in the standard. No friendship or hacks are needed.
- In `ex02`, expose `const_iterator` in addition to `iterator` so the stack can be iterated in `const` contexts — the test driver uses `const MutantStack<int>` and `printIter`.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `main.cpp`, `easyfind.hpp`
- `ex01`: `Makefile`, `main.cpp`, `Span.hpp`, `Span.tpp`, `Span.cpp`
- `ex02`: `Makefile`, `main.cpp`, `MutantStack.hpp`

## Looking Ahead
> **How this connects to later modules.**
- Module 09 is the final C++ module and builds heavily on STL containers: `std::map` for the Bitcoin exchange, `std::stack` for the RPN calculator, and `std::vector` or `std::deque` for the PmergeMe sort.
- The iterator fluency built here — especially understanding `begin`/`end` contracts and range insertion — carries directly into that work.
- `Span`'s approach of accepting any iterator range is the same pattern used by STL algorithms everywhere; understanding it makes the whole standard library feel consistent.

## Snippets from This Repo
- `easyfind` in `ex00` — container-agnostic search through the iterator interface:
```cpp
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
```

- Range `addNumber` in `ex01` — bulk insertion with capacity pre-check:
```cpp
template <typename InputIt>
void	Span::addNumber(InputIt first, InputIt last)
{
	typename std::iterator_traits<InputIt>::difference_type	count;
	unsigned int						add;
	unsigned int						current;

	count = std::distance(first, last);
	if (count <= 0)
		return ;
	add = static_cast<unsigned int>(count);
	current = static_cast<unsigned int>(_numbers.size());

	if (current + add > _capacity)
		throw NoMoreSpace();
	_numbers.insert(_numbers.end(), first, last);
}
```

- Iterator exposure in `ex02` — tapping into `std::stack`'s protected container:
```cpp
typedef typename std::stack<T>::container_type::iterator	iterator;
iterator begin()
{
	return (this->c.begin());
}
iterator end()
{
	return (this->c.end());
}
```
