#include "FragTrap.hpp"

/* Default attribute values specific to FragTrap. */
const int	FragTrap::DEFAULT_HIT_POINTS = 120;
const int	FragTrap::DEFAULT_ENERGY_POINTS = 100;
const int	FragTrap::DEFAULT_ATTACK_DAMAGE = 30;

/*
 * Default constructor.
 *
 * Initializes a FragTrap with default name and FragTrap-specific stats.
 */
FragTrap::FragTrap()
	: ClapTrap("Unnamed")
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;

	std::cout << "FragTrap default constructor called" << std::endl;
}

/*
 * Named constructor.
 *
 * Initializes a FragTrap with a custom name and FragTrap-specific stats.
 */
FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

/*
 * Copy constructor.
 *
 * Creates a FragTrap as a copy of another instance.
 */
FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy assignment operator.
 *
 * Assigns all ClapTrap attributes from another FragTrap.
 */
FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assigment operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	
	return (*this);
}

/*
 * Destructor.
 */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

/*
 * Requests a high five.
 *
 * This is a FragTrap-exclusive action.
 */
void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
		<< " requests a high five! ✋" << std::endl;
}
