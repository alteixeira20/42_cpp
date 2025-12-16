#include "ScavTrap.hpp"

/*
 * Default constructor.
 *
 * Initializes a ScavTrap with ClapTrap defaults,
 * then overrides stats to match ScavTrap specifications.
 */
ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

/*
 * Named constructor.
 *
 * Forwards name to ClapTrap constructor and applies
 * ScavTrap-specific stat values.
 */
ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for "
		<< _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

/*
 * Copy constructor.
 *
 * Relies on ClapTrap copy constructor for base state,
 * then performs assignment to ensure full copy.
 */
ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 *
 * Delegates copying of base attributes to ClapTrap.
 */
ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assigment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

/*
 * Destructor.
 *
 * Displays ScavTrap-specific destruction message.
 * ClapTrap destructor is called automatically after.
 */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

/*
 * Overrides ClapTrap::attack().
 *
 * Uses ScavTrap energy, damage values, and a distinct message
 * as required by the subject.
 */
void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack because it has no hit points!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name
		<< " ferociously attacks " << target
		<< ", dealing " << _attackDamage
		<< " damage! EP left: " << _energyPoints
		<< std::endl;
}

/*
 * Activates Gate Keeper mode.
 *
 * Special ScavTrap-only behavior.
 */
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " has entered Gate keeper mode!"
		<< std::endl;
}
