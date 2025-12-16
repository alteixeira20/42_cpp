#include <iostream>
#include <cstdlib>
#include "Point.hpp"

/*
 * Triangle:
 *
 *      C (5, 10)
 *        /\
 *       /  \
 *      /    \
 * A (0,0)----B (10,0)
 */

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: ./bsp <x> <y>" << std::endl;
		std::cout << "Example: ./bsp 5 5" << std::endl;
		return (1);
	}

	float	x = std::atof(av[1]);
	float	y = std::atof(av[2]);

	Point	A(0, 0);
	Point	B(10, 0);
	Point	C(5, 10);
	Point	P(x, y);

	std::cout << "Point (" << x << ", " << y << "): ";

	if (bsp(A, B, C, P))
		std::cout << "inside triangle" << std::endl;
	else
		std::cout << "outside triangle" << std::endl;

	return (0);
}
