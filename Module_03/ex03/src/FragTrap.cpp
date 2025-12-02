#include "FragTrap.hpp"

const int	FragTrap::DEFAULT_HIT_POINTS = 120;
const int	FragTrap::DEFAULT_ENERGY_POINTS = 100;
const int	FragTrap::DEFAULT_ATTACK_DAMAGE = 30;

// Default Constructor
FragTrap::FragTrap()
	: ClapTrap("Unnamed")
{
	_hitPoints = 121;
	_energyPoints = 101;
	_attackDamage = 31;

	std::cout << "FragTrap default constructor called" << std::endl;
}

// Named Constructor
FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

// Assigment Operator
FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assigment operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	
	return (*this);
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

// Special Action
void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
		<< " requests a high five! ✋" << std::endl;
}
