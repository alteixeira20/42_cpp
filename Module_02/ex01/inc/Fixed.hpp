#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

/*
 * Fixed-point number class.
 *
 * Represents a fixed-point value using an integer storage and a fixed
 * number of fractional bits.
 *
 * This class follows the Orthodox Canonical Form (OCF):
 *  - Default constructor
 *  - Copy constructor
 *  - Copy assignment operator
 *  - Destructor
 */
class	Fixed
{
	public:
		Fixed();				// 1. Default Constructor
		Fixed(const Fixed &other);		// 2. Copy Constructor
		Fixed& operator=(const Fixed &other);	// 3. Assignment Operator
		~Fixed();				// 4. Destructor
		
		// New constructors
		Fixed(const int n);			// Convert int to fixed-point
		Fixed(const float n);			// Convert float to fixed-point

		// Conversion Methods
		float	toFloat() const;		// Convert fixed-point to float
		int	toInt() const;			// Convert fixed-point to int

		// Raw access
		int	getRawBits() const;
		void	setRawBits(int const raw);
	private:
		int			_value;
		static const int	_fractionalBits = 8;
};

/*
** Stream insertion operator overload.
**
** Allows a Fixed object to be printed using standard output streams:
**     std::cout << fixed;
**
** The value is printed as its floating-point representation.
**
** This function is non-member because the left operand is an std::ostream.
*/
std::ostream&	operator<<(std::ostream &out, const Fixed &obj);
#endif
