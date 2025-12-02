#include "Cat.hpp"

// Default Constructor
Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Constructor called - Cat" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other)
	: Animal(other)
{
	std::cout << "Copy Constructor called - Cat" << std::endl;
}

// Copy Assignment
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy Assignment Operator called - Cat" << std::endl;

	if (this != &other)
		Animal::operator=(other);

	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destructor called - Cat" << std::endl;
}

// Make Sound
void	Cat::makeSound() const
{
	std::cout << "Cat starts to Meow!" << std::endl;
}
