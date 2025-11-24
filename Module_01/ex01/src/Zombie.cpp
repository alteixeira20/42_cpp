#include "Zombie.hpp"

// Default Constructor (needed for array Zombie[nbr])
Zombie::Zombie()
	: _name("Unnamed")
{
}

// Constructor with name
Zombie::Zombie(std::string name)
	: _name(name)
{
}

// Destructor
Zombie::~Zombie()
{
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	_name = name;
}
