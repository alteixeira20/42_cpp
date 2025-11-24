#include "Zombie.hpp"

// Allocates mem to heap and returns it's pointer!
Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = new Zombie(name);
	return zombie;
}
