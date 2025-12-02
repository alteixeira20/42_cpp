#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap()
	: ClapTrap("Unnamed_clap_name"),
	ScavTrap("Unnamed"), FragTrap("Unnamed"),
	_name("Unnamed")
{
	_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Named Constructor
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;

	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

// Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

// Use ScavTrap attack
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// Special Ability
void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << _name
		<< ", and my ClapTrap name is " << ClapTrap::_name
		<< std::endl;
}
