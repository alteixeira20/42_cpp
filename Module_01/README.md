<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Stack%20vs%20Heap-0A5F38?style=for-the-badge&logoColor=white" alt="Stack vs Heap badge">
  <img src="https://img.shields.io/badge/Pointers%20%26%20References-7C3AED?style=for-the-badge&logoColor=white" alt="Pointers badge">
  <img src="https://img.shields.io/badge/File%20Streams-1D3557?style=for-the-badge&logoColor=white" alt="File Streams badge">
  <img src="https://img.shields.io/badge/Switch%20Logic-B23A48?style=for-the-badge&logoColor=white" alt="Switch badge">
  <img src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white" alt="Make badge">
</p>

<h1 align="center">Module 01 — Memory, References, and Control Flow</h1>
<p align="center">Stack vs heap choices, references vs pointers, file streams, and control-flow tables—with the same stream discipline from Module 00.</p>

## Where We’re Coming From (Module 00 recap)
- Still on C++98 streams, no `using namespace`, no STL containers.
- Keep classes small with clear ctors/dtors; `const` where state shouldn’t change.

## New in Module 01
- Stack vs heap lifetimes (`new/delete`, arrays with `delete[]`).
- References (always bound) vs pointers (nullable, reassigned).
- File streams (`std::ifstream`/`std::ofstream`) and string search/replace loops.
- Dispatch without if/else forests: member-function pointer tables and switch+fallthrough.

## Exercises (as implemented here)
- **ex00 – BraiiiiiiinnnzzzZ** (`Module_01/ex00/src`): `newZombie` allocates on the heap and logs creation; `randomChump` builds on the stack; ctor/dtor print bite/death so lifetime is visible.
- **ex01 – Moar brainz!** (`Module_01/ex01/src`): `zombieHorde` default-constructs an array, then `setName` for each. Main spawns 42 zombies, announces all, `delete[]` cleans up.
- **ex02 – HI THIS IS BRAIN** (`Module_01/ex02/src/main.cpp`): Prints addresses and values for a string variable, a pointer to it, and a reference alias—showing same storage, different syntax.
- **ex03 – Unnecessary violence** (`Module_01/ex03/src`): `Weapon` uses init-list; `HumanA` stores a `Weapon&` (must be armed at construction), `HumanB` stores a nullable `Weapon*` and prints “has no weapon!” when empty. Weapon type mutations propagate to both.
- **ex04 – Sed is for losers** (`Module_01/ex04/src/main.cpp`): Reads the whole file (appends `\n` per input line), rejects empty search string or empty file, replaces all occurrences with `find`/`erase`/`insert`, writes `<filename>.replace`.
- **ex05 – Harl 2.0** (`Module_01/ex05/src/Harl.cpp`): Parallel arrays of level strings and member-function pointers; `complain` runs the first matching handler; invalid level does nothing. Messages use the bacon text from the subject.
- **ex06 – Harl filter** (`Module_01/ex06/src/Harl.cpp`): Maps level to an index, then `switch` plus labeled fallthrough (`goto`) to print from that level up to ERROR. Unknown level prints `[ Probably complaining about insignificant problems ]`.

## Build & Run
- Always compile with `c++ -Wall -Wextra -Werror -std=c++98`.
- Each exercise has its own `Makefile`: e.g., `make -C ex04 && ./ex04/op_sed input s1 s2`.

## Notes & Pitfalls
- `nullptr` isn’t available in C++98; use `NULL` where needed (see `HumanB`).
- When allocating arrays (`new T[n]`), ensure a default ctor exists and pair with `delete[]` (done in `ex01`).
- In `ex04`, because a newline is appended per `getline`, output will always end with at least one trailing newline.
- `ex05` ignores unknown levels silently; `ex06` reports unknown levels with the neutral message.

## Chain to Next Module
- Module 02 builds on these ownership choices and pushes you into Orthodox Canonical Form and operator overloading; keep the pointer/reference discipline in mind.

## Snippets from This Repo
- Heap vs stack creation (ex00):
```cpp
heapZombie = newZombie("HeapZombie");
randomChump("StackZombie");
```
- `HumanB` nullable weapon (ex03):
```cpp
if (_weapon)
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
else
    std::cout << _name << " has no weapon!" << std::endl;
```
- Sed replace loop (ex04):
```cpp
while ((pos = content.find(search, pos)) != std::string::npos) {
    content.erase(pos, search.length());
    content.insert(pos, replace);
    pos += replace.length();
}
```
- Member-function pointer table (ex05):
```cpp
_levels[0] = "DEBUG"; _funcs[0] = &Harl::debug;
...
if (_levels[i] == level) { (this->*_funcs[i])(); return; }
```
- Switch + labeled fallthrough (ex06):
```cpp
switch (index) {
    case 0: debug(); goto info_label;
    case 1: info_label: info(); goto warning_label;
    ...
}
```
