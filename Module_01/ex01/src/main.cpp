#include "Zombie.hpp"

int	main(void)
{
	int	nbr;
	int	i;

	nbr = 42;

	Zombie*	horde;

	horde = zombieHorde(nbr, "HordeZombie");
	i = 0;
	while (i < nbr)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;

	return (0);
}
