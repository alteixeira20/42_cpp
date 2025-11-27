#include "Zombie.hpp"

// Announce
void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Constructor
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << ": was biten (constructor)!" << std::endl;
}

// Destructor
Zombie::~Zombie(void)
{
	std::cout << _name << ": has died (destructor)!" << std::endl;
}
