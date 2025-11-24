#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie(std::string _name);
		~Zombie(void);
		
		void	announce(void) const;
	private:
		std::string	_name;
};

Zombie*	newZombie(std::string _name);

void	randomChump(std::string _name);

#endif
