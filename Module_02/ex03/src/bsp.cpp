#include "Point.hpp"

/*
 * Computes a signed value based on the relative position of three points.
 *
 * This function uses a 2D cross product to determine the orientation
 * of the point p1 relative to the line formed by p2 and p3.
 *
 * - If the result is positive, p1 is on one side of the line.
 * - If the result is negative, p1 is on the opposite side.
 * - If the result is zero, the three points are collinear
 *   (they lie on the same straight line).
 *
 * This value is later used to determine whether a point lies inside
 * a triangle or exactly on one of its edges.
 */
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed	x1 = p1.getX() - p3.getX();
	Fixed	y1 = p2.getY() - p3.getY();
	Fixed	x2 = p2.getX() - p3.getX();
	Fixed	y2 = p1.getY() - p3.getY();

	Fixed	result = (x1 * y1) - (x2 * y2);
	return (result);
}

/*
 * Checks whether the point lies exactly on one of the triangle edges.
 *
 * If any of the computed signed values is zero, it means the point is
 * collinear with one of the triangle's sides.
 *
 * In this case, the point lies on an edge and must be considered
 * outside of the triangle, since the subject requires the point
 * to be strictly inside.
 */
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

/*
 * Checks whether the point is strictly inside the triangle.
 *
 * The point is inside the triangle if it lies on the same side of
 * all three edges.
 *
 * This happens when all signed values have the same sign:
 * - all positive, or
 * - all negative.
 *
 * If the signs differ, the point lies outside the triangle.
 */
static bool	isInside(const Fixed &d1, const Fixed &d2, const Fixed &d3)
{
	if (d1 > 0 && d2 > 0 && d3 > 0)
		return (true);
	if (d1 < 0 && d2 < 0 && d3 < 0)
		return (true);
	return (false);
}

/*
 * Determines whether a point lies strictly inside a triangle.
 *
 * The function computes the relative position of the point with respect
 * to each edge of the triangle using cross products.
 *
 * - If the point lies on any edge or vertex, the function returns false.
 * - If the point lies on the same side of all edges, it is strictly
 *   inside the triangle and the function returns true.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = sign(point, a, b);
	Fixed	d2 = sign(point, b, c);
	Fixed	d3 = sign(point, c, a);

	if (isOnEdge(d1, d2, d3))
		return (false);
	return (isInside(d1, d2, d3));
}
