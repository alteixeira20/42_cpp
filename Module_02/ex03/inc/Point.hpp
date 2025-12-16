#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

/*
 * Immutable 2D point represented using fixed-point coordinates.
 *
 * Once constructed, a Point's coordinates cannot be modified.
 * This guarantees safe value semantics and prevents accidental mutation.
 */
class	Point
{
	public:
		Point();				// Default Constructor
		Point(float x, float y);		// Constructor with Floats
		Point(const Point &other);		// Copy Constructor
		Point &operator=(const Point &other);	// Assigment Operator
		~Point();				// Destructor
	
		/* Coordinate accessors. */
		Fixed const&	getX() const;
		Fixed const&	getY() const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

/*
 * Determines whether a point lies strictly inside a triangle.
 *
 * Returns true if `point` is strictly inside the triangle defined
 * by points a, b, and c. Returns false otherwise.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
