#include "MateriaSource.hpp"

/*
 * Default constructor.
 * Clears template slots.
 */
MateriaSource::MateriaSource()
{
	int	i;

	i = 0;
	while ( i < 4)
	{
		_materias[i] = NULL;
		i++;
	}
}

/*
 * Copy constructor.
 * Deep-clones learned templates.
 */
MateriaSource::MateriaSource(const MateriaSource &other)
{
	int i = 0;
	while (i < 4)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
		i++;
	}
}

/*
 * Copy assignment operator.
 * Clears current templates and deep-clones from source.
 */
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		int i = 0;
		while (i < 4)
		{
			if (_materias[i])
				delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
			i++;
		}
	}
	return (*this);
}

/*
 * Destructor.
 * Deletes stored templates.
 */
MateriaSource::~MateriaSource()
{
	int i = 0;
	while (i < 4)
	{
		if (_materias[i])
			delete _materias[i];
		i++;
	}
}

/*
 * Learn a materia by cloning it into the first free slot.
 * The passed-in materia is deleted after cloning to avoid leaks.
 */
void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;

	int i = 0;
	while (i < 4)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m->clone();
			delete m;
			return ;
		}
		i++;
	}
	/* Inventory full: delete to avoid leaking the passed materia. */
	delete m;
}

/*
 * Create a new materia by cloning a learned template matching type.
 * Returns NULL if type is unknown.
 */
AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < 4)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
		i++;
	}
	return (NULL);
}
