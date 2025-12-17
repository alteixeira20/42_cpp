#include "Cat.hpp"

/*
 * Default constructor.
 * Initializes the Cat and sets its type to "Cat".
 */
Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Creates a Cat by copying another Cat.
 */
Cat::Cat(const Cat &other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 * Assigns the state of another Cat.
 */
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &other)
		Animal::operator=(other);

	return (*this);
}

/*
 * Destructor.
 * Called when a Cat object is destroyed.
 */
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

/*
 * Overrides Animal::makeSound().
 * Outputs the Cat-specific sound.
 */
void	Cat::makeSound() const
{
	std::cout << "Cat says: Meow!" << std::endl;
}
