<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/STL%20Containers-0A5F38?style=for-the-badge&logoColor=white" alt="STL Containers badge">
  <img src="https://img.shields.io/badge/Parsing-7C3AED?style=for-the-badge&logoColor=white" alt="Parsing badge">
  <img src="https://img.shields.io/badge/Algorithms-1D3557?style=for-the-badge&logoColor=white" alt="Algorithms badge">
  <img src="https://img.shields.io/badge/Ford--Johnson-B23A48?style=for-the-badge&logoColor=white" alt="Ford-Johnson badge">
</p>

<h1 align="center">Module 09 — STL & Applied Algorithms</h1>
<p align="center">Practical use of C++98 containers through data lookup, stack-based calculation, and merge-insert sorting.</p>

## Table of Contents
1. [At a Glance](#at-a-glance)
2. [Learning Objectives](#learning-objectives)
3. [Exercises Overview](#exercises-overview)
4. [Implementation Notes per Exercise](#implementation-notes-per-exercise)
5. [PmergeMe Deep Dive](#pmergeme-deep-dive)
6. [Rules & Constraints](#rules--constraints)
7. [Build & Usage](#build--usage)

## At a Glance
> **Highlights:** Final C++ module focused on choosing and using STL containers properly.
- `ex00` uses `std::map` for sorted date/rate lookup in a Bitcoin exchange calculator.
- `ex01` uses `std::stack` for Reverse Polish Notation, where operands naturally follow LIFO order.
- `ex02` uses `std::vector` and `std::deque` to run the same merge-insert sort and compare timings.
- The module rule matters: containers used in one exercise are not reused in the next one.

## Learning Objectives
> **Goal:** Use STL containers as part of the design, not just as storage.
- Pick containers according to access patterns: ordered lookup, stack operations, indexed sequences.
- Parse input defensively before inserting data into containers.
- Understand how `lower_bound`, `push`, `pop`, `insert`, `swap`, and indexed access shape each solution.
- Explain the Ford-Johnson / merge-insert sorting flow and how the same idea behaves on two containers.
- Measure container processing time without mixing terminal output into the benchmark.

## Exercises Overview
> **What this module builds in this repo.**

| Exercise | Program | Container(s) | Purpose |
| :------: | ------- | ------------ | ------- |
| `ex00` | `btc` | `std::map` | Reads historical BTC rates and converts input amounts using the exact or closest lower date. |
| `ex01` | `RPN` | `std::stack` | Evaluates postfix expressions with single-digit operands and `+ - * /` operators. |
| `ex02` | `PmergeMe` | `std::vector`, `std::deque` | Sorts positive integers with merge-insert sort and prints processing time for both containers. |

## Implementation Notes per Exercise
> **How the solutions are structured.**
- **ex00:** `BitcoinExchange` stores rates in `_rates`, a `std::map<std::string, double>`. `loadDatabase` reads `data.csv`, uses `splitCsvLine` to separate date and rate, validates dates with `isValidDateFormat`, parses numbers with `parseDouble`, and fills the map. `processInputFile` reads `date | value` lines, validates amounts with `parseValue`, then calls `findSpecificRate`. The important lookup happens with `_rates.lower_bound(date)`: if the date is exact, it uses it; otherwise it steps back one iterator to use the closest lower date.
- **ex01:** `RPN::evaluate` reads tokens with `std::istringstream`. Digits are pushed onto a local `std::stack<long>`. Operators are checked with `isOperator`, then `processOperation` applies the operation. The code pops `b` first and `a` second, so `a - b` and `a / b` keep the correct order. A valid expression must finish with exactly one number left on the stack.
- **ex02:** `PmergeMe::run` controls the whole flow: print the original input, time vector processing, time deque processing, print the sorted vector, and display both timings. `fillVector` and `fillDeque` parse the command-line arguments independently through `validateAndParse`, so each container timing includes its own data management plus sorting.

## PmergeMe Deep Dive
> **Highlights:** How the merge-insert sort works in this implementation.

### Input Flow
- `run` starts by validating argument count, clearing `_vec` and `_deq`, and using `fillVector` once to print the original sequence through `printSequence("Before: ", _vec)`.
- `_vec` is cleared after printing so the vector timing starts from an empty container, just like the deque timing.
- `fillVector` and `fillDeque` both call `validateAndParse`, which rejects empty strings, non-digits, zero, negative numbers, overflow, and values above `INT_MAX`.

### Timing Flow
- `getTimeMicros` uses `clock_gettime(CLOCK_MONOTONIC, ...)` and converts the result to microseconds.
- Vector timing measures exactly `fillVector + fordJohnsonSortVector`.
- Deque timing measures exactly `fillDeque + fordJohnsonSortDeque`.
- `std::fixed << std::setprecision(3)` prints readable microsecond values without pretending to have more precision than the timer provides.

### Sorting Flow
- `fordJohnsonSortVector` and `fordJohnsonSortDeque` are separate entry points, one for each container.
- Both functions use the same high-level steps:
  1. Stop immediately if the container has `0` or `1` elements.
  2. Call `splitPairs` to compare elements two by two.
  3. Store smaller values in `a` and larger values in `b`.
  4. If the input size is odd, store the last element as `straggler`.
  5. Recursively sort `b`, the larger side of the pairs.
  6. Copy sorted `b` into the main chain with `buildMainChainVector` or `buildMainChainDeque`.
  7. Build the pending list with `buildPendingVector` or `buildPendingDeque`.
  8. Insert pending values into the main chain with `insertPending`.
  9. Replace the original container with the sorted chain using `swap`.

### Pair Splitting
- `splitPairs` keeps the pair relationship simple: each two-number group is ordered locally before the recursive step.

```cpp
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
```

- This means `b` contains the larger element of each pair, and `a` contains the pending smaller values that will later be inserted.

### Jacobsthal Order
- `buildJacobsthalOrder` creates the order used to insert pending values.
- It starts with index `0`, then uses `nextJacobsthal` to move through Jacobsthal boundaries.
- Inside each boundary, indexes are pushed in reverse order. This is the insertion order used by merge-insert sort to reduce the number of comparisons performed during binary insertion.
- `insertPending` tracks inserted indexes with `std::vector<bool> inserted`, applies the Jacobsthal order first, then inserts any remaining pending values.

### Binary Insertion
- `binaryInsert` searches inside the current sorted chain and inserts the new value at the correct position.
- It uses indexed access, which fits both `std::vector` and `std::deque`.
- When values are equal, the new value is inserted after existing equal values because the search moves right when `value >= chain[mid]`.

```cpp
while (left < right)
{
	mid = left + (right - left) / 2;
	if (value < chain[mid])
		right = mid;
	else
		left = mid + 1;
}
chain.insert(chain.begin() + left, value);
```

### Example
For:
```txt
3 5 9 7 4
```

`splitPairs` produces:
```txt
a: 3 7
b: 5 9
straggler: 4
```

`b` is recursively sorted and becomes the main chain:
```txt
5 9
```

Pending values are:
```txt
3 7 4
```

After Jacobsthal-guided binary insertion:
```txt
3 4 5 7 9
```

## Rules & Constraints
> **Project constraints.**
- Compile with `c++ -Wall -Wextra -Werror`, compatible with `-std=c++98`.
- STL containers are mandatory in this module.
- A container used in one exercise is not reused in another.
- `ex02` uses two different containers and handles sequences of at least 3000 integers.
- Each exercise provides its own Makefile with `all`, `clean`, `fclean`, and `re`.

## Build & Usage
> **Commands used most often.**

```sh
make -C ex00
./ex00/btc ex00/input.txt

make -C ex01
./ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

make -C ex02
./ex02/PmergeMe 3 5 9 7 4
```
