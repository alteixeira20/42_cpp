#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	std::cout << "=== Construction ===" << std::endl;
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);
	Fixed const	e(41.98f);

	std::cout << "\n=== Assignment ===" << std::endl;
	a = Fixed(1234.4321f);

	std::cout << "\n=== Floating-point output ===" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "\n=== Integer output ===" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	return (0);
}

