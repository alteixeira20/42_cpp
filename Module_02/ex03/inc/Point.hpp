#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:
		Point();				// Default Constructor
		Point(float x, float y);		// Constructor with Floats
		Point(const Point &other);		// Copy Constructor
		Point &operator=(const Point &other);	// Assigment Operator
		~Point();				// Destructor
	
		// Get Coord
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
