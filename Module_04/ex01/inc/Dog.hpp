#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog();					// Default Constructor
		Dog(const Dog &other);			// Copy Constructor
		Dog &operator=(const Dog &other);	// Copy Assigment Operator
		virtual	~Dog();				// Destructor
		
		virtual void	makeSound() const;	// Special Ability
		Brain	*getBrain(void) const;		// Getter
	private:
		Brain*	_brain;
};

#endif
