#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	std::cout << "=== Increment operators ===" << std::endl;
	Fixed a;

	std::cout << "a        = " << a << "  (expected 0)" << std::endl;
	std::cout << "++a      = " << ++a << "  (expected 1)" << std::endl;
	std::cout << "a        = " << a << "  (expected 1)" << std::endl;
	std::cout << "a++      = " << a++ << "  (expected 1)" << std::endl;
	std::cout << "a        = " << a << "  (expected 2)" << std::endl;

	std::cout << "\n=== Arithmetic operators ===" << std::endl;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(10) / Fixed(4));
	Fixed const d(Fixed(3) + Fixed(2));
	Fixed const e(Fixed(5) - Fixed(1));

	std::cout << "5.05 * 2 = " << b << "  (expected ~10.10)" << std::endl;
	std::cout << "10 / 4   = " << c << "  (expected 2.5)" << std::endl;
	std::cout << "3 + 2    = " << d << "  (expected 5)" << std::endl;
	std::cout << "5 - 1    = " << e << "  (expected 4)" << std::endl;

	std::cout << "\n=== Min / Max ===" << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b)
	          << "  (expected b)" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b)
	          << "  (expected a)" << std::endl;

	return (0);
}
