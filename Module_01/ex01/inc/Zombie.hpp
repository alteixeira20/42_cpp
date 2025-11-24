#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce() const;
		void	setName(const std::string &name);
	private:
		std::string _name;
};

Zombie*	zombieHorde(int nbr, std::string name);

#endif
