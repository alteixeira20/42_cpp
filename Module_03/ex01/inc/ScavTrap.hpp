#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap();					// Default Constructor
		ScavTrap(const std::string &name);		// Name Constructor
		ScavTrap(const ScavTrap &other);		// Copy Constructor
		ScavTrap &operator=(const ScavTrap &other);	// Assignment Operator
		~ScavTrap();					// Destructor

		void	attack(const std::string &target);	// Override of ClapTrap
		void	guardGate();				// Special Ability
};

#endif
