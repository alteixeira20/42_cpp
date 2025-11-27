#include "Point.hpp"

// Compute signed area using the cross product
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed	result =
		(p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
		(p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
	
	return (result);
}

// Check if Point lies on the triangle lines (edges)
static bool	isOnEdge(const Fixed &d1, const Fixed &d2, const Fixed &d3)
{
	if (d1 == 0)
		return (true);
	if (d2 == 0)
		return (true);
	if (d3 == 0)
		return (true);
	return (false);
}

// Check if Point is inside triangle using the signs
static bool	isInside(const Fixed &d1, const Fixed &d2, const Fixed &d3)
{
	bool	allPositive = false;
	bool	allNegative = false;

	if (d1 > 0 && d2 > 0 && d3 > 0)
		allPositive = true;
	if (d1 < 0 && d2 < 0 && d3 < 0)
		allNegative = true;
	
	if (allPositive)
		return (true);
	if (allNegative)
		return (true);
	return (false);
}

// BSP Function returns true only if Point is inside the triangle
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = sign(point, a, b);
	Fixed	d2 = sign(point, b, c);
	Fixed	d3 = sign(point, c, a);

	if (isOnEdge(d1, d2, d3))
		return (false);
	if (isInside(d1, d2, d3))
		return (true);
	return (false);
}
