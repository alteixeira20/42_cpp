#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();						// Default Constructor
		WrongAnimal(const WrongAnimal &other);			// Copy Constructor
		WrongAnimal &operator=(const WrongAnimal &other);	// Copy Assigment Operator
		~WrongAnimal();						// Destructor
		
		std::string	getType() const;			// Getter
		void		makeSound() const;			// Polymorphic function
	protected:
		std::string	_type;
};

#endif
