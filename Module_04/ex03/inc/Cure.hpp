#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

/*
 * Cure materia
 *
 * Creates the "cure" type, clones itself, and applies the healing effect in use().
 */
class	Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);
		virtual	~Cure();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter &target);
};

#endif
