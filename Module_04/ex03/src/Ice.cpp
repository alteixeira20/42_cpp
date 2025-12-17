#include "Ice.hpp"
#include "ICharacter.hpp"

#include "Ice.hpp"
#include "ICharacter.hpp"

/*
 * Default constructor.
 * Builds an "ice" materia by forwarding type to AMateria.
 */
Ice::Ice()
	: AMateria("ice")
{
}

/*
 * Copy constructor.
 * No additional state; keeps type "ice".
 */
Ice::Ice(const Ice &other)
	: AMateria("ice")
{
	(void)other;
}

/*
 * Copy assignment operator.
 * No-op beyond type consistency; returns self.
 */
Ice	&Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

/* Destructor. */
Ice::~Ice()
{
}

/* Clones this ice materia. */
AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

/* Applies the ice effect to the target. */
void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
