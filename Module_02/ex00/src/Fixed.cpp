#include "Fixed.hpp"

/*
** Default constructor.
** Initializes the fixed-point value to zero.
*/
Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
** Destructor.
** No dynamic resources to release for this class.
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** Copy constructor.
** Creates a new instance as a copy of another Fixed object.
*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
** Copy assignment operator.
** Assigns the value of another Fixed object to this instance.
** Guards against self-assignment.
*/
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

/*
** Returns the raw fixed-point value.
** Does not modify the object.
*/
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/*
** Sets the raw fixed-point value.
*/
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
