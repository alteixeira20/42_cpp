<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Streams-1D3557?style=for-the-badge&logoColor=white" alt="Streams badge">
  <img src="https://img.shields.io/badge/Classes-0A5F38?style=for-the-badge&logoColor=white" alt="Classes badge">
  <img src="https://img.shields.io/badge/Static%20%26%20Const-B23A48?style=for-the-badge&logoColor=white" alt="Static and Const badge">
  <img src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white" alt="Make badge">
</p>

<h1 align="center">Module 00 — C++ Basics</h1>
<p align="center">Kickoff for the 42 C++ cursus: streams, classes, initialization, and disciplined output.</p>

## Table of Contents
1. [At a Glance](#at-a-glance)
2. [Learning Objectives](#learning-objectives)
3. [Key Concepts to Review](#key-concepts-to-review)
4. [Exercises Overview](#exercises-overview)
5. [Rules & Constraints](#rules--constraints)
6. [Approach & Tips](#approach--tips)
7. [What to Deliver](#what-to-deliver)
8. [Looking Ahead](#looking-ahead)

## At a Glance
> **Highlights:** Foundation work to switch from C habits to idiomatic C++.
- Work entirely in C++98 with streams (`std::cout`, `std::cin`) instead of C I/O.
- Model behavior with small classes and member functions; respect access (public/private).
- Practice initialization lists, `const` correctness, and static vs instance context.
- Leave STL containers/algorithms aside here; focus on raw class design and strings.

## Learning Objectives
> **Goal:** Confidently write and wire simple C++ classes with clear I/O.
- Transition from C I/O to C++ stream formatting and manipulators.
- Understand when to keep data private and expose behavior via public methods.
- Apply `const` where state should not change and use static members intentionally.
- Manage compilation with `c++ -Wall -Wextra -Werror -std=c++98` and Makefiles.

## Key Concepts to Review
> **Refresh before coding.**
- Streams: `std::cout`, `std::cin`, `std::cerr`, manipulators (`std::setw`, `std::setfill`, right alignment).
- Namespaces: qualify with `std::` (no `using namespace` here).
- Classes & access specifiers; member functions vs free functions.
- Initialization lists vs assignment inside constructors.
- `const` member functions and `const` data; static data/methods lifetimes.
- Basic string operations (`std::string` length, substr, formatting).

## Exercises Overview
> **What you build and why.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` Megaphone | Normalize input to uppercase with clean stream output. | String traversal, streams, argc/argv handling. |
| `ex01` PhoneBook | Tiny CLI phonebook capped at 8 entries; add/search/exit. | Classes, fixed-size storage, formatting table output, input validation. |
| `ex02` Account (optional) | Recreate missing `Account.cpp` from header/tests/log. | Reading headers, matching expected output, constructors/destructors, static members. |

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compiler: `c++` with `-Wall -Wextra -Werror` and compatible with `-std=c++98`.
- Forbidden: `printf`/`malloc`/`free` and external libs; avoid `using namespace` and `friend`.
- STL containers/algorithms are off-limits until Module 08.
- Headers must guard against double inclusion and be independently includable.
- Any implementation in headers (except templates) is disallowed.

## Approach & Tips
> **Stay efficient and evaluator-friendly.**
- Plan headers first: data members private, behavior public; keep the interface minimal.
- Use initialization lists for member setup; mark non-mutating methods as `const`.
- For `ex01`, predefine column width (10) and truncate with a dot for long fields; validate non-empty fields.
- For `ex02`, read `Account.hpp` and the provided log/tests to mirror exact output (timestamps differ, structure must match).
- Print constructor/destructor traces when helpful to prove lifecycle (especially in `ex02`).

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `megaphone.cpp`.
- `ex01`: `Makefile`, sources/headers (`PhoneBook`, `Contact`, `main`).
- `ex02`: `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp` (if required by subject bundle).

## Looking Ahead
> **How this sets up later modules.**
- Establishes stream-based I/O patterns reused in later parsing-heavy modules.
- Introduces disciplined class boundaries before inheritance and polymorphism arrive in Module 03–04.
- Practices `const` and static usage that become critical when handling exceptions and RAII in Module 05.
