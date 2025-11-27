#include <iostream>
#include "Point.hpp"
#include <cstdlib>

/*
	NOTE:
	You may change these coordinates when testing different shapes,
	but the default triangle is:

	    A = (0, 0)
	    B = (10, 0)
	    C = (5, 10)

	This forms an isosceles triangle centered at x = 5.
*/

int	main(int ac, char **av)
{
	float	x;
	float	y;

	if (ac != 3)
	{
		std::cout << "Usage: ./bsp <x> <y>\n";
		return (1);
	}
	
	x = std::atof(av[1]);
	y = std::atof(av[2]);

	Point	A(0.0f, 0.0f);
	Point	B(10.0f, 0.0f);
	Point	C(5.0f, 10.0f);

	Point	P(x, y);

	bool	result = bsp(A, B, C, P);
	std::cout << std::boolalpha << result << std::endl;
	
	return (0);
}
