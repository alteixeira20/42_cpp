#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
 * Specialized ClapTrap with enhanced durability and defense.
 *
 * ScavTrap inherits from ClapTrap and overrides certain behaviors
 * to reflect its stronger defensive role. It introduces a unique
 * ability (Gate Keeper mode) not available to the base class.
 */
class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap();					// Default Constructor
		ScavTrap(const std::string &name);		// Name Constructor
		ScavTrap(const ScavTrap &other);		// Copy Constructor
		ScavTrap &operator=(const ScavTrap &other);	// Assignment Operator
		~ScavTrap();					// Destructor

		/*
		 * Overrides ClapTrap::attack().
		 * Uses ScavTrap-specific stats and message.
		 */
		void	attack(const std::string &target);
		
		/*
		 * Activates Gate Keeper mode.
		 *
		 * This is a ScavTrap-exclusive ability that represents
		 * a defensive stance.
		 */
		void	guardGate();
};

#endif
