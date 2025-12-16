#include "Fixed.hpp"

/*
 * Default constructor.
 * Initializes the fixed-point value to zero.
 */
Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Destructor.
 * Called when a Fixed object goes out of scope.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Copy constructor.
 * Creates a new Fixed object as a copy of another instance.
 */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 * Assigns the value of another Fixed object to this instance.
 * Handles self-assignment safely.
 */
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

/* Returns the raw fixed-point value. */
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/* Sets the raw fixed-point value directly. */
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*
 * Integer constructor.
 * Converts an integer into fixed-point format by shifting left.
 */
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

/*
 * Floating-point constructor.
 * Converts a float into fixed-point format using rounding.
 */
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (1 << _fractionalBits));
}

/* Converts the fixed-point value to a floating-point number. */
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

/*
 * Stream insertion operator overload.
 * Outputs the fixed-point value as a float.
 */
std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
