#include "Character.hpp"

Character::Character()
	: _name("Default")
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const::string &name)
	: _name(name)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character &other)
{
	int	i;

	_name = other._name;
	i = 0;
	while (i < 4)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
}

Character	&Character::operator=(const Character &other)
{
	int	i;

	if (this != &other)
	{
		_name = other._name;

		i = 0;
		while (i < 4)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
			i++;
		}
	}
	return (*this);
}

Character::~Character()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_inventory[i])
			delete _inventory[i];
		i++;
	}
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	if (!m)
		return ;

	i = 0;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
		i++;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
