#include "Point.hpp"

/*
 * Default constructor.
 *
 * Initializes the point at the origin.
 * An initializer list is required because _x and _y are const.
 */
Point::Point()
	: _x(0), _y(0)
{
}

/*
 * Constructs a point from two floating-point values.
 *
 * The values are converted to fixed-point using the Fixed class.
 */
Point::Point(float x, float y)
	: _x(Fixed(x)), _y(Fixed(y))
{
}

/*
 * Copy constructor.
 *
 * Initializes the const members using another Point's coordinates.
 */
Point::Point(const Point &other)
	: _x(other._x), _y(other._y)
{
}

/*
 * Assignment operator.
 *
 * Since Point is immutable (_x and _y are const),
 * this operator cannot modify the instance.
 */
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

/*
 * Destructor.
 */
Point::~Point()
{
}

/*
 * Returns the x-coordinate.
 */
Fixed const&	Point::getX() const
{
	return (_x);
}

/*
 * Returns the y-coordinate.
 */
Fixed const&	Point::getY() const
{
	return (_y);
}
