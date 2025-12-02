#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();						// Default Constructor
		DiamondTrap(const std::string &name);			// Named Constructor
		DiamondTrap(const DiamondTrap &other);			// Copy
		DiamondTrap &operator=(const DiamondTrap &other);	// Assignment
		~DiamondTrap();						// Destructor
	
		void	attack(const std::string &target);		// Override ScavTrap attack
		void	whoAmI();					// Special Feature
	private:
		std::string	_name;
};

#endif
