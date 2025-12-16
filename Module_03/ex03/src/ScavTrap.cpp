#include "ScavTrap.hpp"

/*
 * Default attribute values specific to ScavTrap.
 */
const int	ScavTrap::DEFAULT_HIT_POINTS = 100;
const int	ScavTrap::DEFAULT_ENERGY_POINTS = 50;
const int	ScavTrap::DEFAULT_ATTACK_DAMAGE = 20;

/*
 * Default constructor.
 *
 * Initializes a ScavTrap with default name and ScavTrap-specific stats.
 * ClapTrap is constructed first due to inheritance.
 */
ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;
}

/*
 * Named constructor.
 *
 * Initializes a ScavTrap with a custom name and ScavTrap-specific stats.
 */
ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for "
		<< name << std::endl;
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;
}

/*
 * Copy constructor.
 *
 * Creates a ScavTrap as a copy of another instance.
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
 * Assigns all ClapTrap attributes from another ScavTrap.
 */
ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assigment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

/* Destructor */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

/*
 * Overridden attack method.
 *
 * Uses ScavTrap-specific attack message and stats.
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
 * This is a ScavTrap-exclusive ability.
 */
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " has entered Gate keeper mode!"
		<< std::endl;
}
