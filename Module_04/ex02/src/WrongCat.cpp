#include "WrongCat.hpp"

/*
 * Default constructor.
 * Sets the type string without virtual dispatch support.
 */
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

/*
 * Copy constructor.
 */
WrongCat::WrongCat(const WrongCat &other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/*
 * Copy assignment operator.
 */
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

/*
 * Destructor.
 */
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/*
 * Non-virtual sound: will not dispatch through WrongAnimal*.
 */
void	WrongCat::makeSound() const
{
	std::cout << "WrongCat meows weirdly..." << std::endl;
}
