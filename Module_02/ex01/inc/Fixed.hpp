#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

/**
 * Overload of the << operator.
 *
 * Allows printing a Fixed object using:
 *      std::cout << obj;
 *
 * Syntax breakdown:
 *  - Returns std::ostream& so we can chain outputs (cout << a << b)
 *  - First argument: the output stream (cout)
 *  - Second argument: the Fixed object to print, passed as a const reference
 *  - Must be a free function because the left operand (ostream) is not Fixed
 *
 * The implementation must print the floating-point representation
 * by calling obj.toFloat().
 */
std::ostream&	operator<<(std::ostream &out, const Fixed &obj);
#endif
