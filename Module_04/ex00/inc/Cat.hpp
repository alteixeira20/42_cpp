#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat();					// Default Constructor
		Cat(const Cat &other);			// Copy Constructor
		Cat &operator=(const Cat &other);	// Copy Assigment Operator
		virtual	~Cat();				// Destructor
		
		virtual void	makeSound() const;	// Special Ability
};

#endif

