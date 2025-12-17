#include "Cat.hpp"

/*
 * Default constructor.
 * Sets type to "Cat" and allocates a fresh Brain.
 */
Cat::Cat()
	: Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Deep-copies the Brain from another Cat.
 */
Cat::Cat(const Cat &other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

/*
 * Copy assignment operator.
 * Deletes current Brain and deep-copies from the source Cat.
 */
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return (*this);
}

/*
 * Destructor.
 * Releases the owned Brain.
 */
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

/* Cat-specific sound. */
void	Cat::makeSound() const
{
	std::cout << "Cat starts to Meow!" << std::endl;
}

/* Exposes the owned Brain pointer. */
Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
