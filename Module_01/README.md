<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Stack%20vs%20Heap-0A5F38?style=for-the-badge&logoColor=white" alt="Stack vs Heap badge">
  <img src="https://img.shields.io/badge/Pointers%20%26%20References-7C3AED?style=for-the-badge&logoColor=white" alt="Pointers badge">
  <img src="https://img.shields.io/badge/File%20Streams-1D3557?style=for-the-badge&logoColor=white" alt="File Streams badge">
  <img src="https://img.shields.io/badge/Switch%20Logic-B23A48?style=for-the-badge&logoColor=white" alt="Switch badge">
  <img src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white" alt="Make badge">
</p>

<h1 align="center">Module 01 — Memory, References, and Control Flow</h1>
<p align="center">Dynamic allocation, pointer vs reference discipline, file streams, and controlled branching in C++98.</p>

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
> **Highlights:** Apply C++ object semantics to memory, ownership, and branching.
- Contrast stack vs heap allocation with explicit constructors/destructors.
- Use references and pointers intentionally (aliases vs nullable indirections).
- Manipulate strings and files via streams instead of C stdio.
- Exercise structured control flow with member-function pointers and switch.

## Learning Objectives
> **Goal:** Be comfortable choosing allocation strategies, passing by ref/pointer, and using streams.
- Allocate, initialize, and destroy arrays of objects without leaks.
- Use references for mandatory ownership and pointers for optional/late binding.
- Work with `std::ifstream`/`std::ofstream` to read/write files safely.
- Replace nested conditionals with function-pointer tables or switch-driven flows.
- Format output with `std::cout` and manipulators, keeping C++98 compliance.

## Key Concepts to Review
> **Refresh before coding.**
- Stack vs heap lifetimes; `new`/`delete` vs automatic objects.
- Constructors, destructors, and initialization lists.
- Pointer basics (`nullptr` is not available in C++98, use `NULL`) vs references (non-null, must bind on init).
- Member function pointers syntax: `&Class::method` and `(instance->*fn)()`.
- File streams: `std::getline`, `is_open`, writing to new files, `.c_str()` when needed.
- `std::string` operations: `find`, `erase`, `insert`, length, and empty checks.
- Switch statement and fallthrough (or explicit cascades) for filtered logging.

## Exercises Overview
> **What you build and why.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` BraiiiiiiinnnzzzZ | Compare heap vs stack zombies and constructor/destructor traces. | Dynamic vs automatic allocation, simple class. |
| `ex01` Moar brainz! | Build a horde of zombies in one allocation. | Arrays of objects, default ctor + setter. |
| `ex02` HI THIS IS BRAIN | Contrast pointer and reference to the same string. | Address/value printing, aliasing semantics. |
| `ex03` Unnecessary violence | Share a `Weapon` between humans with ref vs pointer ownership. | Initialization lists, nullable pointers, const refs. |
| `ex04` Sed is for losers | Reimplement `sed`-style replace into `<file>.replace`. | File streams, string search/replace loop. |
| `ex05` Harl 2.0 | Map log levels to handlers via member-function pointers. | Lookup tables, dispatch without if/else chains. |
| `ex06` Harl filter | Filter logs by minimum level using switch cascade. | Switch, fallthrough via labels, CLI argument handling. |

## Implementation Notes per Exercise
> **How the solutions behave in this repo.**
- **ex00:** `newZombie` allocates on the heap and returns a pointer; `randomChump` creates a stack zombie and announces immediately. Constructors/destructors print who was bitten or died, making lifetime visible.
- **ex01:** `zombieHorde` allocates `Zombie[n]` with the default constructor, then assigns names via `setName`. `main` spawns 42 zombies, announces each, and cleans up with `delete[]`.
- **ex02:** Demonstrates a string variable, a pointer to it, and a reference alias. Prints addresses and values to show identical storage but different access syntax.
- **ex03:** `Weapon` stores type with an init list; `HumanA` holds a `Weapon&` (must be armed at construction), while `HumanB` keeps a nullable `Weapon*` set later. Attacks print the current weapon type; mutable type propagates through shared references/pointers.
- **ex04:** Reads the whole file into a string, replaces all occurrences of `s1` with `s2` using `find`/`erase`/`insert`, then writes to `<filename>.replace`. Guards missing args, empty search string, and file open failures.
- **ex05:** `Harl` initializes parallel arrays of level strings and member-function pointers; `complain` finds the index and invokes the matching handler, otherwise no-op. Tests call each level plus an invalid one.
- **ex06:** CLI expects one level; maps it to an index and uses `switch` with labeled fallthrough to print from that level up to ERROR. Unknown levels print the neutral message. Uses `goto` labels to simulate intentional fallthrough in C++98.

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compiler: `c++` with `-Wall -Wextra -Werror` and compatible with `-std=c++98`.
- Forbidden: `printf`/`malloc`/`free`, external libs, `using namespace` and `friend`.
- STL containers/algorithms remain off-limits until Module 08.
- Headers must have include guards and be self-sufficient; implementation stays in `.cpp`.

## Approach & Tips
> **Stay efficient and evaluator-friendly.**
- Prefer initialization lists for member setup (`Weapon`, `HumanA`); avoids double init.
- Decide pointer vs reference by ownership semantics: nullable/later assignment ⇒ pointer; mandatory/always-valid ⇒ reference.
- When allocating arrays (`new T[n]`), ensure a default constructor exists and pair with `delete[]`.
- For replace logic, advance the search index by the replacement length to avoid infinite loops on overlapping patterns.
- Use member-function pointer tables (ex05) to avoid repetitive conditionals; store both the string keys and function pointers side by side.
- In switch-based filtering (ex06), be explicit about fallthrough; labels keep intent readable in C++98.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `Zombie.cpp`, `Zombie.hpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`.
- `ex01`: `Makefile`, `Zombie.cpp`, `Zombie.hpp`, `zombieHorde.cpp`, `main.cpp`.
- `ex02`: `Makefile`, `main.cpp`.
- `ex03`: `Makefile`, `Weapon.*`, `HumanA.*`, `HumanB.*`, `main.cpp`.
- `ex04`: `Makefile`, `main.cpp` (plus any test files you create, e.g., `test.txt`).
- `ex05`: `Makefile`, `Harl.*`, `main.cpp`.
- `ex06`: `Makefile`, `Harl.*`, `main.cpp`.

## Looking Ahead
> **How this sets up later modules.**
- Reinforces memory ownership choices before classes get richer (Module 02 Canonical Form).
- Builds comfort with references/pointers crucial for inheritance and polymorphism (Module 03–04).
- File/string handling patterns resurface in parsing-heavy later modules.
- Dispatch patterns (function pointers, switch) inform cleaner control flow when exceptions arrive in Module 05.
