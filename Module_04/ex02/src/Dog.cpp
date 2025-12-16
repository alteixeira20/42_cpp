#include "Dog.hpp"

// Default Constructor
Dog::Dog()
	: Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Constructor called - Dog" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other)
	: Animal(other)
{
	std::cout << "Copy Constructor called - Dog" << std::endl;
	_brain = new Brain(*other._brain);
}

// Copy Assignment
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Copy Assignment Operator called - Dog" << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "Destructor called - Dog" << std::endl;
	delete _brain;
}

// Make Sound
void	Dog::makeSound() const
{
	std::cout << "Dog starts to Bark!" << std::endl;
}

// Getter
Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
