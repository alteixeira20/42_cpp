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
};

#endif
