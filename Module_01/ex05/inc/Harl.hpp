#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class	Harl
{
	public:
		Harl();
		void		complain(std::string level);
	private:
		void		debug();
		void		info();
		void		warning();
		void		error();
		void		(Harl::*_funcs[4])();
		std::string	_levels[4];
};

#endif
