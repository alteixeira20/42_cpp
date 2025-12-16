#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
 * FragTrap is a high-energy, high-damage ClapTrap specialization.
 *
 * It introduces a unique interaction ability (highFivesGuys)
 * and defines its own default combat statistics.
 *
 * Virtual inheritance ensures correct behavior when combined
 * with other ClapTrap-derived classes in DiamondTrap.
 */
class	FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void	highFivesGuys();
	protected:
		static const int	DEFAULT_HIT_POINTS;
		static const int	DEFAULT_ENERGY_POINTS;
		static const int	DEFAULT_ATTACK_DAMAGE;
};

#endif
