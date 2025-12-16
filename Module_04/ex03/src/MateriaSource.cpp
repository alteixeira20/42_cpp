#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_materias[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
		i++;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	int	i;

	if (this != &other)
	{
		i = 0;
		while (i < 4)
		{
			if (_materias[i])
				delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_materias[i])
			delete _materias[i];
		i++;
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < 4)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			return ;
		}
		i++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
		i++;
	}
	return (NULL);
}
