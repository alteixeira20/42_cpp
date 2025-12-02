#include "Animal.hpp"

// Default Constructor
Animal::Animal()
	: _type("Animal")
{
	std::cout << "Constructor called - " << _type << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other)
	: _type(other._type)
{
	std::cout << "Copy Constructor called - Animal" << std::endl;
}

// Copy Assignment
Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Copy Assignment Operator called - Animal" << std::endl;

	if (this != &other)
		this->_type = other._type;

	return (*this);
}

// Type Constructor
Animal::Animal(const std::string &type)
	: _type(type)
{
	std::cout << "Constructor called for "
		<< _type
		<< " - Animal"
		<< std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Destructor called - Animal" << std::endl;
}

// Getter
std::string	Animal::getType() const
{
	return (_type);
}

// Make Sound
void	Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound." << std::endl;
}
