<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Classes-0A5F38?style=for-the-badge&logoColor=white" alt="Classes badge">
  <img src="https://img.shields.io/badge/Inheritance-7C3AED?style=for-the-badge&logoColor=white" alt="Inheritance badge">
  <img src="https://img.shields.io/badge/Polymorphism-1D3557?style=for-the-badge&logoColor=white" alt="Polymorphism badge">
  <img src="https://img.shields.io/badge/Exceptions-B23A48?style=for-the-badge&logoColor=white" alt="Exceptions badge">
  <img src="https://img.shields.io/badge/Templates%20%26%20STL-6C63FF?style=for-the-badge&logoColor=white" alt="Templates and STL badge">
</p>

<h1 align="center">42 C++ Modules</h1>
<p align="center">A single, tidy hub for Modules 00–09 of the 42 Porto C++ cursus.</p>

## Table of Contents
1. [At a Glance](#at-a-glance)
2. [Modules & Scope](#modules--scope)
3. [Repository Layout](#repository-layout)
4. [Workflow & Usage](#workflow--usage)
5. [Core Skills](#core-skills)
6. [Tooling & Standards](#tooling--standards)
7. [Module Notes](#module-notes)
8. [Credits](#credits)

## At a Glance
> **Highlights:** Ten steps that build the C++ muscle for the rest of 42 and beyond.
- Modules stack from streams and classes to inheritance, polymorphism, exceptions, templates, and STL.
- Each stage pairs new syntax with design habits: ownership, RAII, deep copies, and safe casting.
- Later modules force real-world patterns: container/iterator fluency, algorithmic thinking, and performance awareness.
- Every folder has its own README to keep focus on the learning goals of that module.

## Modules & Scope
> **Highlights:** What each module teaches and where to find it.
- Each module link opens its folder README for detailed goals, concepts, and notes.

<div align="center">

| Module | Description |
| :----: | ----------- |
| [00](Module_00/) | C++ basics: streams, namespaces, classes, orthodox forms, and static/const hygiene. |
| [01](Module_01/) | Memory ownership, stack vs heap, references/pointers, file streams, and switch-driven flows. |
| [02](Module_02/) | Operator overloading, fixed-point math, and Orthodox Canonical Form discipline. |
| [03](Module_03/) | Inheritance chains and diamond patterns with ClapTrap variants. |
| [04](Module_04/) | Runtime polymorphism, abstract bases, interfaces, and deep-copy brain management. |
| [05](Module_05/) | Exceptions, RAII mindset, and bureaucrat/form workflows with execution guards. |
| [06](Module_06/) | Casting toolbox (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`) plus serialization basics. |
| [07](Module_07/) | Function and class templates; generic utilities with safe iteration and bounds checking. |
| [08](Module_08/) | STL containers/algorithms in practice: span computation, iterable stacks, and bulk insertion patterns. |
| [09](Module_09/) | Full STL application: Bitcoin exchange parsing, RPN evaluation, and Ford–Johnson merge-insert sorting. |

</div>

## Repository Layout
> **Highlights:** Where to start.
- `Module_XX/` – source, Makefile, and a module-specific README (added as each project is completed).
- Root README – quick orientation, module intent, and navigation links.

## Workflow & Usage
> **Highlights:** How to approach each module without surprises.
- Start with the module README to capture rules (C++98, forbidden functions, STL restrictions before Module 08).
- Follow module guidance for build targets, usage examples, and test notes.
- Work one module at a time and keep artifacts inside the matching `Module_XX/`.
- Use provided Makefiles or add your own per module; compile with `-Wall -Wextra -Werror` and C++98 mode.

## Core Skills
> **Highlights:** Learning trajectory across the modules.
- Solid OOP fundamentals: encapsulation, inheritance, and polymorphism with deep-copy discipline.
- Resource safety: RAII patterns, exception handling, and ownership choices on stack vs heap.
- Type expertise: fixed vs floating vs integral math, cast correctness, and template-based genericity.
- STL fluency: containers, iterators, algorithms, and performance-aware implementations on real parsing tasks.

## Tooling & Standards
> **Highlights:** Expectations that stay constant.
- C++98 compliance across all modules; no external deps beyond standard library and readline where allowed.
- STL containers/algorithms reserved for Modules 08–09 as per subject rules.
- Orthodox Canonical Form from Module 02 onward unless explicitly exempted.
- Clean builds and memory hygiene are mandatory; leak checks encouraged (Valgrind/GDB side helpers).

## Module Notes
> **Highlights:** What to expect when opening a module.
- Constructors/destructors are verbose for traceability; many exercises require printed lifecycle messages.
- Module READMEs map code structure to subject requirements, call out edge cases, and include tester notes when relevant.
- Tests live per module; expect iterator-range adders, exception branches, and deep-copy checks where applicable.
