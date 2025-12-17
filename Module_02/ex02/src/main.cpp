#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	/* Increment / Decrement operators (ε behavior)              */

	std::cout << "=== Increment / Decrement operators ===" << std::endl;

	Fixed a;

	std::cout << "Initial a      = " << a << std::endl;

	std::cout << "++a            = " << ++a << std::endl;
	std::cout << "a              = " << a << std::endl;

	std::cout << "a++            = " << a++ << std::endl;
	std::cout << "a              = " << a << std::endl;

	std::cout << "--a            = " << --a << std::endl;
	std::cout << "a              = " << a << std::endl;

	std::cout << "a--            = " << a-- << std::endl;
	std::cout << "a              = " << a << std::endl;

	/* Arithmetic operators                                      */

	std::cout << "\n=== Arithmetic operators ===" << std::endl;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(10) / Fixed(4));
	Fixed const d(Fixed(3) + Fixed(2));
	Fixed const e(Fixed(5) - Fixed(1));

	std::cout << "5.05 * 2 = " << b << std::endl;
	std::cout << "10 / 4   = " << c << std::endl;
	std::cout << "3 + 2    = " << d << std::endl;
	std::cout << "5 - 1    = " << e << std::endl;

	/* Comparison operators                                      */

	std::cout << "\n=== Comparison operators ===" << std::endl;

	Fixed x(2);
	Fixed y(10);

	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "x <  y : " << (x < y) << std::endl;
	std::cout << "x >  y : " << (x > y) << std::endl;
	std::cout << "x <= y : " << (x <= y) << std::endl;
	std::cout << "x >= y : " << (x >= y) << std::endl;
	std::cout << "x == y : " << (x == y) << std::endl;
	std::cout << "x != y : " << (x != y) << std::endl;

	/* ========================================================= */
	/* Min / Max                                                 */
	/* ========================================================= */

	std::cout << "\n=== Min / Max ===" << std::endl;

	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

	return 0;
}
