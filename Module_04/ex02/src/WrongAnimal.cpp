#include "WrongAnimal.hpp"

/*
 * Default constructor.
 * Initializes the wrong hierarchy base with type "WrongAnimal".
 */
WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Copies the type string.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &other)
	: _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 * Transfers the type from another WrongAnimal.
 */
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

/*
 * Destructor.
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* Returns the type string. */
std::string	WrongAnimal::getType() const
{
	return _type;
}

/*
 * Non-virtual sound to demonstrate static binding issues.
 */
void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes some weird sound..." << std::endl;
}
