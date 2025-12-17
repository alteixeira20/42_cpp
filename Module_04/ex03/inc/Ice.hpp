#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

/*
 * Ice materia
 *
 * Creates the "ice" type, clones itself, and applies the ice bolt effect in use().
 */
class	Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice	&operator=(const Ice &other);
		virtual	~Ice();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter &target);
};

#endif
