<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Templates-0A5F38?style=for-the-badge&logoColor=white" alt="Templates badge">
  <img src="https://img.shields.io/badge/Function%20Templates-7C3AED?style=for-the-badge&logoColor=white" alt="Function templates badge">
  <img src="https://img.shields.io/badge/Template%20Classes-1D3557?style=for-the-badge&logoColor=white" alt="Template classes badge">
  <img src="https://img.shields.io/badge/Generic%20Programming-B23A48?style=for-the-badge&logoColor=white" alt="Generic programming badge">
</p>

<h1 align="center">Module 07 — C++ Templates</h1>
<p align="center">Type-agnostic utilities, generic iteration, and a bounds-checked array class built entirely with function and class templates.</p>

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
> **Highlights:** move from runtime cast mechanics into compile-time generic programming with function and class templates.
- `ex00` implements three type-agnostic utilities — `swap`, `min`, and `max` — as function templates in a single header.
- `ex01` introduces `iter`, a function template that applies any callable to every element of a raw array, with both mutable and const overloads.
- `ex02` wraps a heap-allocated buffer in a template class `Array` that enforces bounds checking, value-initialization, and deep copy semantics.
- Templates live entirely in headers here: no `.cpp` needed for function templates, and `Array.tpp` is included at the bottom of `Array.hpp`.

## Learning Objectives
> **Goal:** write code that is correct for any type without repeating logic, and understand what the compiler does at instantiation time.
- Define function templates and understand when the compiler deduces type arguments automatically.
- Write a template that accepts both mutable and const arrays without duplicating logic.
- Build a template class with Orthodox Canonical Form: default constructor, parameterized constructor, copy constructor, assignment operator, destructor.
- Enforce invariants at runtime through exceptions even inside a template context.
- Understand why template definitions must be visible at the point of instantiation.

## Key Concepts to Review
> **Refresh before coding.**
- Template type deduction: when the compiler infers `T` and when you must specify it explicitly.
- The difference between a function template overload and a specialization.
- Why template implementations belong in headers (or `.tpp` files included by headers) rather than `.cpp` files.
- Value-initialization with `new T[n]()` versus default-initialization with `new T[n]`.
- Deep copy vs. shallow copy when the class owns a heap-allocated buffer.
- Why `size_t` wraps on underflow and what that means for negative-looking indices like `a[-1]`.

## Exercises Overview
> **What this module builds in this repo.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` whatever | Swap two values and find the min or max of two values for any type. | Function templates, type deduction, header-only. |
| `ex01` iter | Apply a function to every element of a raw array of any type. | Template functions, const overloads, callable parameters. |
| `ex02` Array | A type-safe, bounds-checked dynamic array with canonical form. | Template classes, deep copy, exception on out-of-bounds access. |

## Implementation Notes per Exercise
- **ex00:** All three utilities live in `whatever.hpp` and are never instantiated directly — the compiler generates the right version on demand. `swap` uses a temporary of type `T`, `min` and `max` return `const T &` to avoid unnecessary copies. Your test driver covers `int` (basic and equal values), `std::string`, and `float` to confirm that type deduction works across multiple types in the same binary.
  Run: `make -C ex00 && ./ex00/whatever`

- **ex01:** `iter` is templated on both the element type `T` and the callable type `F`, so it accepts function pointers, functors, and explicit template instantiations interchangeably. A second overload handles `const T *` arrays to prevent modifying elements through a const pointer. The test driver shows four scenarios: printing and mutating an `int` array, read-only access to a `const int` array (with a commented-out mutation attempt that should not compile), printing a `std::string` array, and uppercasing a `char` array.
  Run: `make -C ex01 && ./ex01/iter`

- **ex02:** `Array<T>` stores a `T *_data` buffer and a `size_t _size`. The default constructor sets both to zero/`NULL`. The parameterized constructor calls `new T[n]()` to value-initialize every element. The assignment operator handles self-assignment, deletes the old buffer, allocates a fresh one, and copies element by element. `operator[]` (and its `const` variant) throw `Array::OutOfBounds` when the index is out of range. The test driver validates the default constructor, parameterized constructor, read-write through `operator[]`, const access, copy construction independence, assignment deep copy, self-assignment safety, out-of-bounds exceptions for both underflow and overflow indices, and instantiation with `double` and `std::string`.
  Run: `make -C ex02 && ./ex02/array`

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compile with `c++ -Wall -Wextra -Werror`, still compatible with `-std=c++98`.
- Forbidden: `printf`, `malloc`, `free`, external libraries, `using namespace`, `friend`.
- STL containers and algorithms are still off-limits until Modules 08 and 09.
- Template definitions must be in header files or files included by headers — no separate `.cpp` for template implementations.
- `Array` must follow Orthodox Canonical Form.

## Approach & Tips
> **What matters during implementation.**
- In `ex00`, return `const T &` from `min` and `max` to avoid copying; the caller can always copy the result if needed.
- In `ex01`, the second overload for `const T *` is necessary if you want `iter` to compile with const arrays; without it the compiler cannot bind a `const int *` to a `T *`.
- In `ex02`, always guard against `_size == 0` before allocating, and remember that `new T[0]` is technically valid but unnecessary.
- In `ex02`, `size_t` is unsigned, so `a[-1]` wraps to a very large value and is caught by the `idx >= _size` check without any special-case code.
- Keep `Array.tpp` protected by its own include guard so it is safe to include multiple times.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `main.cpp`, `whatever.hpp`
- `ex01`: `Makefile`, `main.cpp`, `iter.hpp`
- `ex02`: `Makefile`, `main.cpp`, `Array.hpp`, `Array.tpp`

## Looking Ahead
> **How this connects to later modules.**
- Module 08 builds directly on template fluency: you will use STL containers (`std::list`, `std::map`, `std::stack`) and write template functions that operate on them.
- Module 09 extends that into STL algorithms and a Bitcoin exchange project that ties containers, parsing, and error handling together.
- The discipline of thinking in terms of any type — not a specific one — carries forward into every algorithm and data structure you write from here on.

## Snippets from This Repo
- All three utilities in `ex00` share the same pattern — one template, zero duplication:
```cpp
template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}
```

- `iter` in `ex01` — mutable and const paths share identical loop logic:
```cpp
template <typename T, typename F>
void	iter(T *arr, size_t len, F f)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}
```

- Bounds-checked `operator[]` in `ex02` — unsigned wrap makes the check symmetric:
```cpp
template <typename T>
T	&Array<T>::operator[](size_t idx)
{
	if (idx >= _size)
		throw OutOfBounds();
	return (_data[idx]);
}
```
