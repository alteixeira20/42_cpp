#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
 * FragTrap
 *
 * A high-damage ClapTrap variant.
 * FragTrap specializes ClapTrap by using higher hit points,
 * higher energy points, and increased attack damage.
 *
 * It introduces a unique special action: highFivesGuys().
 */
class	FragTrap : public ClapTrap
{
	public:
		/* Orthodox Canonical Form */
		FragTrap();					// Default constructor
		FragTrap(const std::string &name);		// Named constructor
		FragTrap(const FragTrap &other);		// Copy constructor
		FragTrap &operator=(const FragTrap &other);	// Assignment operator
		~FragTrap();					// Destructor

		/*
		 * Requests a high five.
		 * Special ability unique to FragTrap.
		 */
		void	highFivesGuys();
};

#endif
