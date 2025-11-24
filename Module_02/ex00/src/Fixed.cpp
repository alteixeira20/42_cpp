#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
