#include "DiamondTrap.hpp"

/*
 * Default constructor.
 *
 * Initializes the single ClapTrap base (virtual inheritance) with a
 * special suffixed name, as required by the subject.
 *
 * Attribute sources:
 *  - Hit points     -> FragTrap
 *  - Energy points  -> ScavTrap
 *  - Attack damage  -> FragTrap
 */
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

/*
 * Named constructor.
 *
 * The ClapTrap base is initialized with <name>_clap_name,
 * while DiamondTrap keeps its own distinct name.
 */
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;

	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

/*
 * Copy constructor.
 *
 * Copies all base subobjects and the DiamondTrap-specific name.
 */
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 *
 * Assigns the ClapTrap base and the DiamondTrap name.
 */
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

/* Destructor */
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

/*
 * Attack function.
 *
 * Explicitly uses ScavTrap's attack implementation, as required.
 */
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/*
 * Displays both the DiamondTrap name and the underlying ClapTrap name.
 *
 * Demonstrates the dual identity imposed by the diamond inheritance.
 */
void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << _name
		<< ", and my ClapTrap name is " << ClapTrap::_name
		<< std::endl;
}
