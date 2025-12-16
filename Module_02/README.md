<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Orthodox%20Canonical%20Form-0A5F38?style=for-the-badge&logoColor=white" alt="OCF badge">
  <img src="https://img.shields.io/badge/Operator%20Overloading-7C3AED?style=for-the-badge&logoColor=white" alt="Operators badge">
  <img src="https://img.shields.io/badge/Fixed--Point%20Math-1D3557?style=for-the-badge&logoColor=white" alt="Fixed-point badge">
  <img src="https://img.shields.io/badge/Geometry-B23A48?style=for-the-badge&logoColor=white" alt="Geometry badge">
</p>

<h1 align="center">C++ Module 02 — Fixed-Point, Operators, BSP</h1>
<p align="center">Orthodox Canonical Form everywhere, custom numeric type, and a first geometry helper.</p>

## From Modules 00–01 to 02
- Keep C++98 streams, no STL containers, no `using namespace`.
- Classes now must follow Orthodox Canonical Form (default ctor, copy ctor, copy assign, dtor).
- Reuse memory/pointer discipline from Module 01; add operator overloading and const-correctness pressure.

## Key Concepts in This Repo
- **Fixed-point storage (8 fractional bits):** store `raw = roundf(float * 256)`. `toFloat` divides by 256; `toInt` shifts right 8.
- **Operator overloading:** comparisons, arithmetic, prefix/postfix ++/-- (see code behavior below), `min/max` returning references.
- **OCF with const members:** `Point` coords are `const`; assignment is a no-op because they cannot change.
- **BSP test:** cross-product signs to decide if a point is strictly inside a triangle; edges/vertices count as outside.

## Exercises (as implemented here)
- **ex00 – My First Class in OCF** (`Module_02/ex00/src`): `Fixed` stores raw value, logs ctor/dtor/getRawBits. Main tests default/copy/assign, self-assignment, chained assignment, and copy independence.
  - Run: `make -C ex00 && ./ex00/Fixed`
- **ex01 – Towards a more useful fixed-point** (`Module_02/ex01/src`): Adds int/float ctors, `toFloat`, `toInt`, and stream `<<` (prints float). Main builds several values and prints float/int views.
  - Run: `make -C ex01 && ./ex01/Fixed`
- **ex02 – Now we’re talking** (`Module_02/ex02/src`): Adds comparisons, arithmetic, ++/--, and `min/max`. Important: ++/-- add/subtract `1 << 8` (step of 1.0 in our code, not 1/256). Division by zero returns `Fixed(0)` instead of crashing. `min/max` return references (const and non-const overloads).
  - Run: `make -C ex02 && ./ex02/Fixed`
  - Main demos pre/post inc, multiply/divide/add/sub, and `min/max`.
- **ex03 – BSP** (`Module_02/ex03/src`): Same `Fixed`; `Point` is immutable. `bsp` computes three signed areas, returns false on edges/vertices or mixed signs. Main uses triangle (0,0)-(10,0)-(5,10) and a CLI point: `./bsp 5 5` → `inside triangle`.
  - Run: `make -C ex03 && ./ex03/bsp <x> <y>` or `make -C ex03 test` to run the bundled test matrix from the Makefile.

## Rules
- Compile: `c++ -Wall -Wextra -Werror -std=c++98`.
- Forbidden: `printf`, `malloc/free`, external libs, `using namespace`, `friend`.
- No STL containers/algorithms until Module 08.
- Headers are guarded and self-contained; implementations stay in `.cpp`.

## Tips Aligned with the Code
- Postfix ops save a copy, mutate, return the old value.
- `Fixed` arithmetic uses integer math internally; multiplication shifts down, division shifts up to preserve scale.
- `Point` members are `const`, so assignment is a no-op; copies must be built via constructors.
- For `bsp`, any zero cross-product means “on edge” → return false, matching the subject’s “strictly inside” rule.

## Chain Forward
- Module 03 will layer inheritance on top of these OCF classes; keep operator and copy-control habits sharp.

## Snippets from This Repo
- Fixed multiplication (ex02/ex03):
```cpp
long tmp = (long)_value * (long)other._value;
result.setRawBits(tmp >> _fractionalBits);
```
- Division guard (ex02/ex03):
```cpp
if (other._value == 0)
    return Fixed(0);
```
- Prefix vs postfix (ex02):
```cpp
Fixed& operator++()
{
    _value += (1 << _fractionalBits); return *this;
}

Fixed operator++(int)
{
    Fixed tmp(*this);
    _value += (1 << _fractionalBits);
    return tmp;
}
```
- BSP sign calculation (ex03):
```cpp
Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed x1 = p1.getX() - p3.getX();
    Fixed y1 = p2.getY() - p3.getY();
    Fixed x2 = p2.getX() - p3.getX();
    Fixed y2 = p1.getY() - p3.getY();
    return (x1 * y1) - (x2 * y2);
}
```
