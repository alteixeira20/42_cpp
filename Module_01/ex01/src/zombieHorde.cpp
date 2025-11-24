#include "Zombie.hpp"


Zombie*	zombieHorde(int nbr, std::string name)
{
	Zombie*	horde;
	int	i;

	horde = new Zombie[nbr];
	i = 0;
	while (i < nbr)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}
