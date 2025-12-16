#include "ClapTrap.hpp"

/*
 * Default attribute values for ClapTrap.
 * These constants define the baseline stats shared by all derived classes.
 */
const int	ClapTrap::DEFAULT_HIT_POINTS = 10;
const int	ClapTrap::DEFAULT_ENERGY_POINTS = 10;
const int	ClapTrap::DEFAULT_ATTACK_DAMAGE = 0;

/*
 * Default constructor.
 *
 * Initializes a ClapTrap with default name and base statistics.
 */
ClapTrap::ClapTrap()
	: _name("Unnamed"),
	  _hitPoints(DEFAULT_HIT_POINTS),
	  _energyPoints(DEFAULT_ENERGY_POINTS),
	  _attackDamage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
 * Named constructor.
 *
 * Initializes a ClapTrap with a custom name and default statistics.
 */
ClapTrap::ClapTrap(const std::string &name)
	: _name(name),
	_hitPoints(DEFAULT_HIT_POINTS),
	_energyPoints(DEFAULT_ENERGY_POINTS),
	_attackDamage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

/*
 * Copy constructor.
 *
 * Creates a new ClapTrap as a copy of another instance.
 */
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 *
 * Assigns all internal state from another ClapTrap.
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
 * Virtual destructor.
 *
 * Ensures proper cleanup when deleting derived objects through base pointers.
 */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}


/*
 * Attacks a target if the ClapTrap has sufficient hit points and energy.
 *
 * Consumes one energy point per attack.
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
 * Reduces hit points by the given amount.
 *
 * A ClapTrap cannot take damage if it is already destroyed.
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
 * Repairs the ClapTrap by increasing hit points.
 *
 * Consumes one energy point.
 * Repairing is not possible if the ClapTrap is destroyed.
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

/*
 * Returns the current energy points.
 *
 * Useful for testing and derived-class logic.
 */
int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}
