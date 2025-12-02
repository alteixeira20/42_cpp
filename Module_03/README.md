<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Inheritance-0A5F38?style=for-the-badge&logoColor=white" alt="Inheritance badge">
  <img src="https://img.shields.io/badge/Method%20Overrides-7C3AED?style=for-the-badge&logoColor=white" alt="Overrides badge">
  <img src="https://img.shields.io/badge/Diamond%20Problem-1D3557?style=for-the-badge&logoColor=white" alt="Diamond badge">
  <img src="https://img.shields.io/badge/Stateful%20Objects-B23A48?style=for-the-badge&logoColor=white" alt="State badge">
</p>

<h1 align="center">Module 03 — Inheritance & Specialization</h1>
<p align="center">Build a family of ClapTraps, layer behaviors through inheritance, and resolve diamond quirks.</p>

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
> **Highlights:** Practice single and multiple inheritance while keeping lifecycles and state straight.
- Start with a base ClapTrap and progressively specialize stats and behavior.
- Override methods cleanly and reuse base logic through protected members.
- Navigate a diamond hierarchy (ClapTrap ← ScavTrap/FragTrap ← DiamondTrap) without ambiguity.
- Keep stateful rules (HP/EP/AD) consistent across derived classes.

## Learning Objectives
> **Goal:** Extend and combine behaviors via inheritance without breaking object state.
- Use protected members to share data across derived classes.
- Override functions while respecting base contracts and adding flavor.
- Chain constructors/destructors correctly and observe order in multiple inheritance.
- Resolve name clashes and pick the right base implementation (e.g., ScavTrap::attack).
- Maintain consistent stat initialization across the hierarchy.

## Key Concepts to Review
> **Refresh before coding.**
- Constructor/destructor chaining; order of base/derived calls.
- Access specifiers: `protected` vs `private` in base classes.
- Overriding vs hiding; calling a specific base implementation (`ScavTrap::attack`).
- Multiple inheritance basics and diamond issues; ensuring one ClapTrap subobject.
- Default values and static constants for shared defaults (HP/EP/AD).

## Exercises Overview
> **What you build and why.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` ClapTrap | Baseline robot with HP/EP/AD and simple actions. | State checks, basic methods, OCF. |
| `ex01` ScavTrap | Derive from ClapTrap with boosted stats and guard mode. | Inheritance, overrides, new ability. |
| `ex02` FragTrap | Another derived type with different stats and high five. | Alternative specialization, shared base logic. |
| `ex03` DiamondTrap | Combine ScavTrap + FragTrap into one (diamond). | Multiple inheritance, name handling, method resolution. |

## Implementation Notes per Exercise
> **How the solutions behave in this repo.**
- **ex00:** `ClapTrap` stores name/HP/EP/AD; guards actions when HP or EP are zero. Constructors/destructor log calls. Attack/repair consume EP; damage floors HP at 0.
- **ex01:** `ClapTrap` members made protected. `ScavTrap` sets HP 100 / EP 50 / AD 20, overrides `attack` with custom messaging, adds `guardGate`. Copy/assign reuse `ClapTrap` logic.
- **ex02:** `FragTrap` sets HP 100 / EP 100 / AD 30, adds `highFivesGuys`. Inherits ClapTrap behavior; logs lifecycle.
- **ex03:** `DiamondTrap` inherits `ScavTrap` and `FragTrap`. Uses ScavTrap’s attack, FragTrap’s HP/AD, ScavTrap’s EP. Stores its own `_name` while `ClapTrap::_name` gets `<name>_clap_name`. `whoAmI` prints both names. Copy/assign forward to base; destructor order shows the diamond unwinding. Includes EP exhaustion test to ensure state checks hold.

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compiler: `c++` with `-Wall -Wextra -Werror`, compatible with `-std=c++98`.
- Forbidden: `printf`/`malloc`/`free`, external libs, `using namespace`, `friend`.
- STL containers/algorithms still off-limits until Module 08.
- Headers must be guarded and self-contained; implementation in `.cpp`.

## Approach & Tips
> **Stay efficient and evaluator-friendly.**
- Initialize stats in constructors, not post-construction assignments; reuse base ctors.
- When overriding, call base checks if appropriate or fully replace behavior consistently.
- In multiple inheritance, be explicit about which base method to use (e.g., `ScavTrap::attack`).
- Keep default values as constants to avoid magic numbers and to coordinate between bases.
- Ensure copy/assignment propagate both base and derived state; watch for slicing.
- Add diagnostic output thoughtfully to verify ctor/dtor order and method resolution.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`.
- `ex01`: `Makefile`, `ClapTrap.*`, `ScavTrap.*`, `main.cpp`.
- `ex02`: `Makefile`, `ClapTrap.*`, `FragTrap.*`, `main.cpp`.
- `ex03`: `Makefile`, `ClapTrap.*`, `ScavTrap.*`, `FragTrap.*`, `DiamondTrap.*`, `main.cpp`.

## Looking Ahead
> **How this sets up later modules.**
- Inheritance patterns here prepare for abstract bases and polymorphism in Module 04.
- State and lifecycle discipline informs RAII and exceptions in Module 05.
- Understanding multiple inheritance clarifies interface design choices in future modules.
