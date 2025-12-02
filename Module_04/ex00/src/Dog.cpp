#include "Dog.hpp"

// Default Constructor
Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Constructor called - Dog" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "Copy Constructor called - Dog" << std::endl;
}

// Copy Assignment
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Copy Assignment Operator called - Dog" << std::endl;

	if (this != &other)
		Animal::operator=(other);

	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "Destructor called - Dog" << std::endl;
}

// Make Sound
void	Dog::makeSound() const
{
	std::cout << "Dog starts to Bark!" << std::endl;
}
