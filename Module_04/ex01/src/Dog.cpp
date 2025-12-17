#include "Dog.hpp"

/*
 * Default constructor.
 * Sets type to "Dog" and allocates a fresh Brain.
 */
Dog::Dog()
	: Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Deep-copies the Brain from another Dog.
 */
Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

/*
 * Copy assignment operator.
 * Deletes current Brain and deep-copies from the source Dog.
 */
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

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
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

/*
 * Dog-specific sound.
 */
void	Dog::makeSound() const
{
	std::cout << "Dog starts to Bark!" << std::endl;
}

/* Exposes the owned Brain pointer. */
Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
