#include "Dog.hpp"

/*
 * Default constructor.
 * Initializes the Dog and sets its type to "Dog".
 */
Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Creates a Dog by copying another Dog.
 */
Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 * Assigns the state of another Dog.
 */
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &other)
		Animal::operator=(other);

	return (*this);
}

/*
 * Destructor.
 * Called when a Dog object is destroyed.
 */
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/*
 * Overrides Animal::makeSound().
 * Outputs the Dog-specific sound.
 */
void	Dog::makeSound() const
{
	std::cout << "Dog says: Woof!" << std::endl;
}
