<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Casts-0A5F38?style=for-the-badge&logoColor=white" alt="Casts badge">
  <img src="https://img.shields.io/badge/Static%20Utilities-7C3AED?style=for-the-badge&logoColor=white" alt="Static utilities badge">
  <img src="https://img.shields.io/badge/Serialization-1D3557?style=for-the-badge&logoColor=white" alt="Serialization badge">
  <img src="https://img.shields.io/badge/RTTI-B23A48?style=for-the-badge&logoColor=white" alt="RTTI badge">
</p>

<h1 align="center">Module 06 — C++ Casts</h1>
<p align="center">Literal conversion, pointer reinterpretation, and runtime type identification through the four C++ cast families.</p>

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
> **Highlights:** move from polymorphism and exceptions into explicit type conversion.
- `ex00` parses scalar literals, detects their category, and prints the corresponding `char`, `int`, `float`, and `double` views.
- `ex01` demonstrates raw pointer serialization with `reinterpret_cast` and round-trips a `Data*` through `uintptr_t`.
- `ex02` uses polymorphism plus `dynamic_cast` to recover the real runtime type behind a `Base*` or `Base&`.
- The module-wide rule matters here: each exercise should clearly justify the cast it uses.

## Learning Objectives
> **Goal:** understand what each cast does, when it is valid, and what guarantees it does or does not provide.
- Distinguish parsing from conversion in scalar handling.
- Use `static_cast` for explicit scalar conversions once the source value is known.
- Use `reinterpret_cast` for raw pointer-to-integer and integer-to-pointer transformations.
- Use `dynamic_cast` for safe downcasting in polymorphic hierarchies.
- Keep utility classes non-instantiable when they only expose static behavior.

## Key Concepts to Review
> **Refresh before coding.**
- The difference between a literal’s textual form and its stored runtime value.
- Pseudo-literals: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.
- Overflow, impossible conversions, and non-displayable `char` values.
- `uintptr_t` as the integer type capable of holding a pointer value.
- Why `dynamic_cast` needs a polymorphic base class with a virtual function.
- Pointer vs reference behavior with `dynamic_cast`: `NULL` for pointers, exceptions for references.

## Exercises Overview
> **What this module builds in this repo.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` ScalarConverter | Convert one literal into four scalar views. | Parsing, `static_cast`, formatting, edge cases. |
| `ex01` Serializer | Convert `Data*` to `uintptr_t` and back. | `reinterpret_cast`, identity round-trip, pointer semantics. |
| `ex02` Identify real type | Detect whether a generated object is `A`, `B`, or `C`. | `dynamic_cast`, RTTI, polymorphic base behavior. |

## Implementation Notes per Exercise
- **ex00:** `ScalarConverter` is a non-instantiable utility with a single static `convert()` entry point. Your implementation first classifies the input (`char`, `int`, `float`, `double`, pseudo-literal, or invalid), then parses to `double`, and finally prints each target type with dedicated helpers from `Printer.cpp`. It correctly handles the sample subject cases like `0`, `nan`, and `42.0f`, while reporting `impossible` or `Non displayable` where appropriate.  
  Run: `make -C ex00 && ./ex00/converter 42.0f`

- **ex01:** `Serializer` is also non-instantiable and intentionally minimal: `serialize()` turns `Data*` into `uintptr_t`, and `deserialize()` turns that raw integer back into `Data*`. In this repo, `Data` is a small struct with one integer member `n`, and `main.cpp` tests stack data, heap data, `NULL`, and a deliberately tampered raw value to show that only exact round-trips are safe to dereference.  
  Run: `make -C ex01 && ./ex01/serializer`

- **ex02:** `Base` is a polymorphic root with a public virtual destructor, and `A`, `B`, `C` are empty derived marker types. `generate()` randomly allocates one of the three and prints which branch was created. `identify(Base*)` uses pointer-based `dynamic_cast`, while `identify(Base&)` performs three reference casts and catches failures until one succeeds. Your test driver runs ten random generations plus two extra checks: a `NULL` pointer for the pointer overload and a plain `Base` object that resolves to `Unknown`.  
  Run: `make -C ex02 && ./ex02/identify`

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compile with `c++ -Wall -Wextra -Werror`, still compatible with `-std=c++98`.
- Forbidden: `printf`, `malloc`, `free`, external libraries, `using namespace`, `friend`.
- STL containers and algorithms are still off-limits until Modules 08 and 09.
- Module 06 adds one extra rule: each exercise must use the appropriate cast type on purpose.
- `std::typeinfo` is forbidden in `ex02`.

## Approach & Tips
> **What matters during implementation.**
- In `ex00`, separate type detection from output formatting; it keeps overflow and pseudo-literal handling manageable.
- Use `static_cast` only after you know the source value is valid for the target representation.
- In `ex01`, remember that serialization here is only about preserving the pointer bit pattern, not cloning pointed-to data.
- In `ex02`, reference-based `dynamic_cast` throws on failure, so exception control flow is expected.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, all `*.cpp`, and all `*.{hpp,h}`
- `ex01`: `Makefile`, `Serializer.*`, `Data` structure files or definition, `main.cpp`
- `ex02`: `Makefile`, `Base.*`, `Identify.*`, `main.cpp`

## Looking Ahead
> **How this connects to later modules.**
- Module 07 shifts from runtime typing concerns to compile-time generic programming with templates.
- The care you build here around valid conversions helps later when iterators, containers, and template deduction become more implicit.
- RTTI and explicit casts also sharpen your understanding of when polymorphism is the right tool and when it is a workaround.

## Snippets from This Repo
- Scalar classification funnels everything through one dispatcher:
```cpp
type = detectType(str);
if (type == TYPE_INVALID)
{
	printInvalid();
	return ;
}
if (type == TYPE_PSEUDO)
{
	printPseudo(str);
	return ;
}
```

- `reinterpret_cast` round-trip in `ex01`:
```cpp
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
```

- Pointer and reference identification paths in `ex02`:
```cpp
if (dynamic_cast<A *>(p) != NULL)
	std::cout << "A" << std::endl;
else if (dynamic_cast<B *>(p) != NULL)
	std::cout << "B" << std::endl;
```

```cpp
try
{
	(void)dynamic_cast<A &>(p);
	std::cout << "A" << std::endl;
	return ;
}
catch (std::exception &)
{
}
```
