<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Orthodox%20Canonical%20Form-0A5F38?style=for-the-badge&logoColor=white" alt="OCF badge">
  <img src="https://img.shields.io/badge/Operator%20Overloading-7C3AED?style=for-the-badge&logoColor=white" alt="Operators badge">
  <img src="https://img.shields.io/badge/Fixed--Point%20Math-1D3557?style=for-the-badge&logoColor=white" alt="Fixed-point badge">
  <img src="https://img.shields.io/badge/Geometry-B23A48?style=for-the-badge&logoColor=white" alt="Geometry badge">
</p>

<h1 align="center">Module 02 — Fixed-Point Numbers & Ad-hoc Polymorphism</h1>
<p align="center">Orthodox Canonical Form, operator overloading, and fixed-point arithmetic leading into simple geometry.</p>

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
> **Highlights:** Build a reusable number type and flex operator overloading with strict lifecycle control.
- Apply the Orthodox Canonical Form (OCF) to every class: default ctor, copy ctor, assignment, destructor.
- Implement a fixed-point numeric type with conversions and overloaded operators.
- Use comparisons, arithmetic, and increment/decrement to make custom types feel native.
- Leverage fixed-point math to solve a geometry inclusion test (BSP) without floating drift.

## Learning Objectives
> **Goal:** Treat user-defined types like built-ins while respecting object lifetime rules.
- Design classes in OCF so copies/assignments are explicit and safe.
- Convert between raw fixed-point storage and human-friendly int/float views.
- Overload operators (comparison, arithmetic, inc/dec) correctly and efficiently.
- Write static helpers (`min`/`max`) that work on const and non-const refs.
- Apply numeric types to solve problems (triangle point inclusion) without STL containers.

## Key Concepts to Review
> **Refresh before coding.**
- Orthodox Canonical Form and when to implement/omit logging.
- Fixed-point representation: storing scaled integers (`value << fractionalBits`), rounding floats.
- Operator overloading rules: returning by value vs reference, prefix vs postfix semantics.
- Const-correctness in methods and return types; passing by const reference.
- Immutable members (`const` fields) and consequences for assignment operators.
- Basic geometry with cross products for point-in-triangle tests.

## Exercises Overview
> **What you build and why.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` My First Class in OCF | Skeleton Fixed storing raw bits with full OCF. | Constructors/assignment/destructor, raw accessors. |
| `ex01` Towards a more useful fixed-point | Add int/float conversions and stream output. | Scaling, rounding, `toFloat`/`toInt`, `operator<<`. |
| `ex02` Now we’re talking | Make Fixed act like a number: comparisons, arithmetic, ++/--, min/max. | Operator overloading, static utilities. |
| `ex03` BSP | Use Fixed in a Point class and test triangle inclusion. | Const members, copy semantics limits, cross-product sign test. |

## Implementation Notes per Exercise
> **How the solutions behave in this repo.**
- **ex00:** `Fixed` stores `_value` and `_fractionalBits=8`. OCF prints lifecycle calls; `getRawBits` logs access. `setRawBits` writes directly.
- **ex01:** Adds `Fixed(int)` and `Fixed(float)` converting via shifts/`roundf`. `toFloat`/`toInt` expose human-readable values. `operator<<` streams `toFloat`. Lifecycle logging kept for visibility.
- **ex02:** Silences ctor/dtor logs for cleaner arithmetic demos. Implements all comparison and arithmetic operators by converting to float and returning new Fixed. Prefix/postfix ++/-- adjust `_value`. Static `min`/`max` overloads handle const/non-const refs. Used to chain operations and compare results.
- **ex03:** `Point` holds `const Fixed _x/_y`; must be initialized in init lists. Assignment operator is a no-op because members are const. `bsp` computes signed areas via cross products (`sign`) and returns false for edge hits; true only when all signs share the same sign (strictly inside). Reuses the richer `Fixed` from ex02.

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compiler: `c++` with `-Wall -Wextra -Werror`, compatible with `-std=c++98`.
- Forbidden: `printf`/`malloc`/`free`, external libs, `using namespace`, `friend`.
- STL containers/algorithms still off-limits until Module 08.
- Classes must follow OCF unless explicitly exempt; no function bodies in headers (templates only).
- Header guards required; headers should be self-contained.

## Approach & Tips
> **Stay efficient and evaluator-friendly.**
- Use init lists consistently, especially for `const` members (`Point` coordinates).
- Avoid code duplication: implement core arithmetic with float conversions, then reuse across operators.
- For postfix ++/--, return a copy of the original state; for prefix, return `*this`.
- In `min`/`max`, return references to avoid temporaries; implement const and non-const variants.
- In `bsp`, treat zero-area cases as outside; ensure edge points return false per subject.
- Keep logging under control: helpful in ex00/01, muted in ex02/03 for clean output.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `Fixed.hpp`, `Fixed.cpp`, `main.cpp`.
- `ex01`: `Makefile`, `Fixed.hpp`, `Fixed.cpp`, `main.cpp`.
- `ex02`: `Makefile`, `Fixed.hpp`, `Fixed.cpp`, `main.cpp`.
- `ex03`: `Makefile`, `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`.

## Looking Ahead
> **How this sets up later modules.**
- OCF discipline becomes mandatory going forward.
- Operator overloading patterns carry into casting and template work (Module 06–07).
- Fixed-point/geometry practice builds numeric intuition useful for later algorithmic tasks.
- Const-member handling foreshadows managing resources and polymorphic bases in Modules 03–04.
