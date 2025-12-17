#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

/*
 * Concrete Animal: Dog
 *
 * Represents a specific Animal that overrides makeSound().
 */
class	Dog: public Animal
{
	public:
		Dog();					// Default Constructor
		Dog(const Dog &other);			// Copy Constructor
		Dog &operator=(const Dog &other);	// Copy Assigment Operator
		virtual	~Dog();				// Destructor
		virtual void	makeSound() const;	// Special Ability
};

#endif
