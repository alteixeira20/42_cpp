#include "Animal.hpp"

/*
 * Default constructor.
 * Initializes the Animal with a generic type.
 */
Animal::Animal()
	: _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/*
 * Constructor with type.
 * Allows derived classes to set their own type.
 */
Animal::Animal(const std::string &type)
	: _type(type)
{
	std::cout << "Animal constructor called for type: "
		<< _type << std::endl;
}

/*
 * Copy constructor.
 * Creates a copy of another Animal.
 */
Animal::Animal(const Animal &other)
	: _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 * Assigns the state of another Animal.
 */
Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &other)
		_type = other._type;

	return (*this);
}

/*
 * Virtual destructor.
 * Required for proper cleanup through base class pointers.
 */
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Returns the type of the animal */
std::string	Animal::getType() const
{
	return (_type);
}

/*
 * Default sound behavior.
 * Intended to be overridden by derived classes.
 */
void	Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound." << std::endl;
}
