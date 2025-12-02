#include "Cat.hpp"

// Default Constructor
Cat::Cat()
	: Animal("Cat")
{
	_brain = new Brain();
	
	std::cout << "Constructor called - Cat" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other)
	: Animal(other)
{
	std::cout << "Copy Constructor called - Cat" << std::endl;
	_brain = new Brain(*other._brain);
}

// Copy Assignment
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy Assignment Operator called - Cat" << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destructor called - Cat" << std::endl;
	delete _brain;
}

// Make Sound
void	Cat::makeSound() const
{
	std::cout << "Cat starts to Meow!" << std::endl;
}

// Getter
Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
