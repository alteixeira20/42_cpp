#include "Point.hpp"

// Default Constructor
// 	Must use initializer list because _x and _y are const
Point::Point()
	: _x(0), _y(0)
{
}

// Construct 2 floats via Fixed class
Point::Point(float x, float y)
	: _x(Fixed(x)), _y(Fixed (y))
{
}

// Copy Constructor
// 	Initializes the const members using the other object's value
Point::Point(const Point &other)
	: _x(other._x), _y(other._y)
{
}

// Assignment Operator
// 	Since _x and _y are const we cannot assign new values to them.
// 	So this operator must return without doing anything (overload)
Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

// Destructor
Point::~Point()
{
}

// Getters
Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
