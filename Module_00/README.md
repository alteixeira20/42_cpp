<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Streams-1D3557?style=for-the-badge&logoColor=white" alt="Streams badge">
  <img src="https://img.shields.io/badge/Classes-0A5F38?style=for-the-badge&logoColor=white" alt="Classes badge">
  <img src="https://img.shields.io/badge/Static%20%26%20Const-B23A48?style=for-the-badge&logoColor=white" alt="Static and Const badge">
  <img src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white" alt="Make badge">
</p>

<h1 align="center">Module 00 — C++ Basics</h1>
<p align="center">Kickoff for the 42 C++ cursus: streams, tiny classes, initialization lists, and disciplined output.</p>

## Overview
- Work in C++98 with streams (`std::cout`, `std::cin`, `std::cerr`) instead of C stdio.
- Model data with small classes; keep members private and expose behavior via methods.
- Practice initialization lists, `const` correctness, and static vs instance context.
- No STL containers/algorithms yet; pure strings and arrays.

## Concepts to Bring from C
- Replace `printf/scanf` with iostreams and manipulators (`std::setw`, right alignment).
- Namespaces: qualify with `std::` (no `using namespace`).
- Constructors/destructors, member vs free functions, header guards.
- `const` data/functions, static class members, simple `std::string` slicing/truncation.

## Exercises (as implemented here)
- **ex00 – Megaphone** (`Module_00/ex00/src/megaphone.cpp`): Uppercases each `argv` chunk with `std::toupper`; if no args, prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
  - Run: `make -C ex00 && ./ex00/megaphone "shhhhh..." Damnit`.
- **ex01 – PhoneBook** (`Module_00/ex01/src`): Fixed 8-slot phonebook, overwrites oldest via modulo `_index`. Rejects empty fields. `SEARCH` shows a 10-char wide table, truncating with a dot. Index must be a single digit 0–7; empty slots are skipped.
  - Run: `make -C ex01 && ./ex01/phonebook`.
  - Output matches subject table (right-aligned, `.` truncation).
- **ex02 – Account (optional)** (`Module_00/ex02/src/Account.cpp`): Rebuilt from header/tests/log. Tracks static totals, refuses overdrafts with `withdrawal:refused`. Timestamps use `std::localtime` format `[YYYYMMDD_HHMMSS]`.
  - Run: `make -C ex02 && ./ex02/tests | tee my_output.log`.

## Rules
- Compile: `c++ -Wall -Wextra -Werror -std=c++98`.
- Forbidden: `printf`, `malloc/free`, external libs, `using namespace`, `friend`.
- Headers self-contained with include guards; no implementations in headers (non-templates).

## Notes & Tips
- Prefer initialization lists; mark non-mutating methods `const`.
- For `ex01`, keep fixed width 10 and truncate with a dot; index parsing is single-character.
- For `ex02`, match the log structure exactly; totals update alongside per-account data.

## Chain to Next Modules
- Module 01 builds on this: same stream discipline, adds stack vs heap, references/pointers, and file streams.
- Module 02 assumes you’re fluent with constructors/destructors and adds Orthodox Canonical Form plus operator overloading.

## Snippets from This Repo
- Megaphone loop (uppercasing argv):
```cpp
while (i < argc) {
    print_upper(argv[i]);
    i++;
}
```
- PhoneBook truncation and table layout:
```cpp
std::cout << std::setw(10) << truncateField(_contacts[i].getFirstName()) << "|";
```
- Account overdraft refusal:
```cpp
if (withdrawal > _amount) {
    _displayTimestamp();
    output << " index:" << _accountIndex << ";p_amount:" << previous
           << ";withdrawal:refused";
    ft_print(output.str(), true);
    return (false);
}
```
