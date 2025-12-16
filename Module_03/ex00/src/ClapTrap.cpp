#include "ClapTrap.hpp"

/*
 * Default constructor.
 *
 * Initializes a ClapTrap with a default name and
 * the base stats defined by the subject.
 */
ClapTrap::ClapTrap()
	: _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
 * Constructs a ClapTrap with a given name.
 *
 * The ClapTrap starts with default hit points,
 * energy points, and attack damage.
 */
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

/*
 * Copy constructor.
 *
 * Creates a new ClapTrap by copying the state
 * of an existing one.
 */
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 *
 * Copies all internal state from another ClapTrap,
 * guarding against self-assignment.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/*
 * Destructor.
 *
 * Outputs a message to trace object lifetime.
 */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*
 * Attempts to attack a target.
 *
 * The attack consumes one energy point and is only possible
 * if the ClapTrap has both hit points and energy remaining.
 */
void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage
		<< " points of damage! EP left: " << _energyPoints
		<< std::endl;
}

/*
 * Applies damage to the ClapTrap.
 *
 * If the ClapTrap is already destroyed, no further
 * damage is applied. Hit points are never negative.
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	
	std::cout << "ClapTrap " << _name
		<< " took " << amount << " damage! HP left: " << _hitPoints
		<< std::endl;
}

/*
 * Repairs the ClapTrap.
 *
 * Restores hit points while consuming energy.
 * This action is only possible if the ClapTrap
 * is alive and has available energy.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot repair because it is destroyed!"
			<< std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " has no energy to repair!"
			<< std::endl;
		return ;
	}

	_energyPoints--;
	_hitPoints += amount;

	std::cout << "ClapTrap " << _name
		<< " repairs itself for " << amount
		<< " HP! New HP: " << _hitPoints
		<< " | EP left: " << _energyPoints
		<< std::endl;
}
