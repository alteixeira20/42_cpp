#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
 * ScavTrap is a specialized ClapTrap with enhanced durability
 * and a unique defensive ability.
 *
 * It overrides the attack behavior and introduces Gate Keeper mode.
 *
 * Virtual inheritance is used to ensure that DiamondTrap contains
 * only one ClapTrap subobject.
 */
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
