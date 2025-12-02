#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	public:
		Animal();				// Default Constructor
		Animal(const std::string &type);	// Type Constructor
		Animal(const Animal &other);		// Copy Constructor
		Animal &operator=(const Animal &other);	// Copy Assigment Operator
		virtual	~Animal();			// Destructor
		
		std::string	getType() const;	// Getter
		virtual void	makeSound() const;	// Polymorphic function
	protected:
		std::string	_type;
};

#endif
