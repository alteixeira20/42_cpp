#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();					// Default Constructor
		ClapTrap(const ClapTrap &other);		// Copy Constructor
		ClapTrap &operator=(const ClapTrap &other);	// Copy Assigment Operator
		~ClapTrap();					// Destructor

		ClapTrap(const std::string &name);		// Required Constructor
		
		// Member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;
};

#endif
