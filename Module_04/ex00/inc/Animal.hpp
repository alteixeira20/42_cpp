#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

/*
 * Base class representing a generic animal.
 *
 * This class is designed to be used polymorphically.
 * It provides a virtual destructor and a virtual makeSound()
 * method that derived classes must override.
 */
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
		/*
		 * Type of the animal.
		 * Accessible to derived classes for initialization.
		 */
		std::string	_type;
};

#endif
