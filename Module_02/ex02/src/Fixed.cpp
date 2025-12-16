#include "Fixed.hpp"

/*
 * Default constructor.
 * Initializes the fixed-point value to zero.
*/
Fixed::Fixed()
	: _value(0)
{
}

/* Destructor. */
Fixed::~Fixed()
{
}

/*
 * Copy constructor.
 * Creates a new Fixed object as a copy of another.
 */
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

/*
 * Copy assignment operator.
 * Assigns the value of another Fixed object to this instance.
 */
Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

/*
 * Integer constructor.
 * Converts an integer to fixed-point representation.
 */
Fixed::Fixed(const int n)
{
	_value = n << _fractionalBits;
}

/*
 * Floating-point constructor.
 * Converts a float to fixed-point representation using rounding.
 */
Fixed::Fixed(const float n)
{
	_value = roundf(n * (1 << _fractionalBits));
}

/* Converts the fixed-point value to a float. */
float	Fixed::toFloat() const
{
	return ((float)_value / (1 << _fractionalBits));
}

/*
 * Converts the fixed-point value to an integer.
 * Fractional bits are discarded.
 */
int	Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

/* Returns the raw fixed-point value. */
int	Fixed::getRawBits() const
{
	return (_value);
}

/* Sets the raw fixed-point value directly. */
void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/*
** Stream insertion operator.
** Outputs the fixed-point value as a floating-point number.
*/
std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

/* Comparison Operators */

bool	Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

/* Arithmetic Operators */

/*
 * Addition.
 * Adds two fixed-point values.
 */
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_value + other._value);
	return (result);
}

/*
 * Subtraction.
 * Subtracts two fixed-point values.
 */
Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_value - other._value);
	return (result);
}

/*
 * Multiplication.
 * Multiplies two fixed-point values and rescales the result.
 */
Fixed	Fixed::operator*(const Fixed &other) const
{
	long	tmp;
	Fixed	result;

	tmp = (long)_value * (long)other._value;
	result.setRawBits(tmp >> _fractionalBits);
	return (result);
}

/*
 * Division.
 * Divides two fixed-point values and preserves precision.
 */
Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._value == 0)
		return Fixed(0);
	
	Fixed	result;
	long	tmp;
	
	tmp = ((long)_value << _fractionalBits) / other._value;
	result.setRawBits(tmp);
	return (result);
}

/* ====================== Increment / Decrement ====================== */

/* Prefix increment. */
Fixed&	Fixed::operator++()
{
	_value += (1 << _fractionalBits);
	return (*this);
}

/* Prefix decrement. */
Fixed&	Fixed::operator--()
{
	_value -= (1 << _fractionalBits);
	return (*this);
}

/* Postfix increment. */
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	_value += (1 << _fractionalBits);
	return (tmp);
}

/* Postfix decrement. */
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	_value -= (1 << _fractionalBits);
	return (tmp);
}

/* Min */

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

/* Max */

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
