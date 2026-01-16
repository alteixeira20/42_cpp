<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Polymorphism-0A5F38?style=for-the-badge&logoColor=white" alt="Polymorphism badge">
  <img src="https://img.shields.io/badge/Abstract%20Classes-7C3AED?style=for-the-badge&logoColor=white" alt="Abstract badge">
  <img src="https://img.shields.io/badge/Deep%20Copy-1D3557?style=for-the-badge&logoColor=white" alt="Deep copy badge">
  <img src="https://img.shields.io/badge/Interfaces-B23A48?style=for-the-badge&logoColor=white" alt="Interfaces badge">
</p>

<h1 align="center">Module 04 — Polymorphism & Abstract Design</h1>
<p align="center">Subtype polymorphism, deep-copy resource ownership, and interface-style design with Materia.</p>

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
> **Highlights:** Build real runtime polymorphism and manage ownership safely.
- Use virtual methods and virtual destructors to guarantee correct dynamic dispatch.
- Introduce deep-copy ownership with `Brain` to avoid shallow-copy pitfalls.
- Convert base classes into abstract interfaces with pure virtual methods.
- Implement a Materia system that mirrors RPG-style equipment and cloning rules.

## Learning Objectives
> **Goal:** Write polymorphic class hierarchies that behave correctly through base pointers.
- Understand how virtual dispatch changes behavior compared to non-virtual methods.
- Implement deep copies when classes own heap resources.
- Enforce abstract base classes to prevent invalid instantiation.
- Use interface-style classes (`ICharacter`, `IMateriaSource`) for clean contracts.
- Manage dynamic allocations with clear ownership and cleanup paths.

## Key Concepts to Review
> **Refresh before coding.**
- Virtual methods, vtables, and why base destructors must be virtual.
- Pure virtual functions and abstract classes.
- Deep copy vs shallow copy; copy constructor and assignment operator for owned memory.
- Object slicing and why base pointers are used for polymorphism.
- Cloning patterns (`clone()`) to duplicate dynamic types safely.
- Inventory management with fixed-size arrays and `NULL` slots in C++98.

## Exercises Overview
> **What you build and why.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` Polymorphism | Base `Animal` with `Dog`/`Cat` and virtual `makeSound()`. | Virtual dispatch, base pointers, destructor chaining. |
| `ex01` Brain & deep copy | `Dog`/`Cat` own a `Brain` on the heap. | Deep copy, destructor cleanup, array of `Animal*`. |
| `ex02` Abstract class | `Animal` becomes abstract; add Wrong hierarchy. | Pure virtuals, static binding pitfalls. |
| `ex03` Interfaces & Materia | `AMateria`, `Ice`, `Cure`, `Character`, `MateriaSource`. | Interface contracts, clone/use, inventory management. |

## Implementation Notes per Exercise
> **How the solutions behave in this repo.**
- **ex00:** `Animal` provides `getType()` and virtual `makeSound()`. `Dog` and `Cat` override sounds. `main` constructs `Animal`, `Dog`, `Cat` via base pointers, tests dynamic dispatch, and deletes through base to confirm virtual destructor behavior.
- **ex01:** `Brain` owns 100 ideas with bounds checks. `Dog`/`Cat` allocate `Brain` in ctors, deep-copy it in copy ctor/assignment, and delete it in dtors. `Tester.cpp` provides `test_polymorphism`, `test_deepcopy_dog`, and `test_deepcopy_cat` to validate sound dispatch and deep-copy independence.
- **ex02:** `Animal` is abstract (`makeSound()` pure virtual). Adds `WrongAnimal`/`WrongCat` to demonstrate missing virtuals. `Tester.cpp` adds `test_wrong_polymorphism` showing static binding and incorrect destructor calls. Main runs polymorphism + deep-copy tests plus wrong hierarchy demo.
- **ex03:** `AMateria` defines `clone()` and `use()`. `Ice` and `Cure` override `clone` and `use` messages. `Character` stores 4-slot inventory, equips first free slot, and uses a `_floor` buffer to track unequipped materias. `MateriaSource` learns up to 4 templates and clones by type. `main` exercises learning, equipping, inventory limits, unequip behavior, and deep-copy of `Character`.

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compiler: `c++` with `-Wall -Wextra -Werror`, compatible with `-std=c++98`.
- Forbidden: `printf`/`malloc`/`free`, external libs, `using namespace`, `friend`.
- STL containers/algorithms still off-limits until Module 08.
- Headers must be guarded and self-contained; implementation in `.cpp`.

## Approach & Tips
> **Stay efficient and consistent.**
- Always make base destructors virtual when deleting via base pointers.
- For deep copy, delete existing owned resources before allocating new copies.
- Keep base classes minimal and focused; move behavior to derived classes where required.
- Validate array indices in `Brain` and inventory slots in `Character`.
- Use `clone()` consistently to preserve dynamic type when copying through base pointers.
- In `MateriaSource::learnMateria`, decide ownership rules clearly; this implementation clones then deletes the original to avoid leaks.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `Animal.*`, `Dog.*`, `Cat.*`, `main.cpp`.
- `ex01`: `Makefile`, `Animal.*`, `Dog.*`, `Cat.*`, `Brain.*`, `Tester.*`, `main.cpp`.
- `ex02`: `Makefile`, `Animal.*`, `Dog.*`, `Cat.*`, `Brain.*`, `WrongAnimal.*`, `WrongCat.*`, `Tester.*`, `main.cpp`.
- `ex03`: `Makefile`, `AMateria.*`, `Ice.*`, `Cure.*`, `ICharacter.hpp`, `IMateriaSource.hpp`, `Character.*`, `MateriaSource.*`, `main.cpp`.

## Looking Ahead
> **How this sets up later modules.**
- Abstract interfaces and cloning patterns prepare you for exception-safe design in Module 05.
- Deep-copy discipline is critical before templates and containers appear in Module 07–08.
- Polymorphism here sets the mental model for dynamic casts and RTTI in Module 06.
