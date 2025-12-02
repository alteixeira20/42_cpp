#include "ClapTrap.hpp"


const int	ClapTrap::DEFAULT_HIT_POINTS = 10;
const int	ClapTrap::DEFAULT_ENERGY_POINTS = 10;
const int	ClapTrap::DEFAULT_ATTACK_DAMAGE = 0;

// Default Constructor
ClapTrap::ClapTrap()
	: _name("Unnamed"), _hitPoints(11), _energyPoints(11), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

// Copy assigment Operator
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

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// Main Constructor
ClapTrap::ClapTrap(const std::string &name)
	: _name(name),
	_hitPoints(DEFAULT_HIT_POINTS),
	_energyPoints(DEFAULT_ENERGY_POINTS),
	_attackDamage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

// Member Functions
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

int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}
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
