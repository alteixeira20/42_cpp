#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed()
	: _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

float	Fixed::toFloat() const
{
	return ((float)_value / (1 << _fractionalBits));
}

int	Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

// Comparison Operators
bool	Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

// Arithmetic Operators
Fixed	Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Prefix Increment & Decrement
Fixed&	Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	_value--;
	return (*this);
}

// Postfix Increment & Decrement
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	_value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_value--;
	return (temp);
}

// Get Min and Max between 2 numbers
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
