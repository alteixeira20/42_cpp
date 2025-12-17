#include "Animal.hpp"

/*
 * Default constructor.
 * Initializes a generic Animal with type "Animal".
 */
Animal::Animal()
	: _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/*
 * Constructor with explicit type.
 * Lets derived classes set their own type label.
 */
Animal::Animal(const std::string &type)
	: _type(type)
{
	std::cout << "Animal constructor called for type: " << _type << std::endl;
}

/*
 * Copy constructor.
 * Copies the type from another Animal.
 */
Animal::Animal(const Animal &other)
	: _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 * Replaces this Animal's type with another's.
 */
Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &other)
		this->_type = other._type;

	return (*this);
}

/*
 * Virtual destructor.
 * Ensures proper cleanup through base-class pointers.
 */
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Returns the type string. */
std::string	Animal::getType() const
{
	return (_type);
}

/*
 * Default sound behavior.
 * Derived classes override with specific sounds.
 */
void	Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound." << std::endl;
}
