#include "AMateria.hpp"
#include "ICharacter.hpp"

/* Base materia constructed with a given type string. */
AMateria::AMateria(std::string const &type)
	: _type(type)
{
	std::cout << "[AMateria] constructed (" << _type << ")" << std::endl;
}

/* Virtual destructor. */
AMateria::~AMateria()
{
	std::cout << "[AMateria] destroyed (" << _type << ")" << std::endl;
}

/* Returns the materia type. */
std::string const	&AMateria::getType() const
{
	return (_type);
}

/* Default use does nothing; derived classes override with effects. */
void	AMateria::use(ICharacter &target)
{
	(void)target;
}
