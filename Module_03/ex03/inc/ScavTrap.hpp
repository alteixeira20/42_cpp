#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();					// Default Constructor
		ScavTrap(const std::string &name);		// Name Constructor
		ScavTrap(const ScavTrap &other);		// Copy Constructor
		ScavTrap &operator=(const ScavTrap &other);	// Assignment Operator
		~ScavTrap();					// Destructor

		void	attack(const std::string &target);	// Override of ClapTrap
		void	guardGate();				// Special Ability
	protected:
		static const int	DEFAULT_HIT_POINTS;
		static const int	DEFAULT_ENERGY_POINTS;
		static const int	DEFAULT_ATTACK_DAMAGE;
};

#endif
