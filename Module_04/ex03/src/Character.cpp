#include "Character.hpp"

/*
 * Default constructor.
 * Initializes empty inventory and floor slots with a default name.
 */
Character::Character()
	: _name("Default"), _floorCount(0)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		_floor[i] = NULL;
		i++;
	}
}

/*
 * Named constructor.
 * Initializes empty inventory and floor slots.
 */
Character::Character(const std::string &name)
	: _name(name), _floorCount(0)
{
	int	i;
	
	std::cout << "[Character] constructed: " << _name << std::endl;
	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		_floor[i] = NULL;
		i++;
	}
}

/*
 * Copy constructor.
 * Deep-clones equipped materia; floor is reset (no borrowed ownership).
 */
Character::Character(const Character &other)
	: _name(other._name), _floorCount(0)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		_floor[i] = NULL;
		i++;
	}
}

/*
 * Copy assignment operator.
 * Clears current inventory, deep-clones from the source, and resets floor slots.
 */
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

			if (_floor[i])
			{
				delete _floor[i];
				_floor[i] = NULL;
			}
			i++;
		}
		_floorCount = 0;
	}
	return (*this);
}

/*
 * Destructor.
 * Deletes owned inventory and any tracked floor materia.
 */
Character::~Character()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (_floor[i])
			delete _floor[i];
		i++;
	}
}

/* Returns the character name. */
std::string const	&Character::getName() const
{
	return (_name);
}

/*
 * Equip a materia in the first free slot.
 * No-op if inventory is full or materia is NULL.
 */
void	Character::equip(AMateria* m)
{
	int	i;

	if (!m)
	{
		std::cout << "[Character] equip ignored (null)" << std::endl;
		return;
	}

	i = 0;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "[Character] " << _name
				<< " equipped " << m->getType()
				<< " in slot " << i << std::endl;
			return ;
		}
		i++;
	}
	// Inventory full: discard to avoid leaking the passed materia.
	std::cout << "[Character] inventory full, deleting materia ("
          << m->getType() << ")" << std::endl;
	delete m;
}

/*
 * Unequip a slot without deleting the materia.
 * Drops it into a small "floor" buffer to avoid leaks.
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "[Character] unequip failed (slot " << idx << ")" << std::endl;
		return;
	}

	std::cout << "[Character] " << _name
	          << " unequipped " << _inventory[idx]->getType()
	          << " from slot " << idx << std::endl;

	if (_floorCount < 4)
		_floor[_floorCount++] = _inventory[idx];
	else
	{
		std::cout << "[Character] floor full, deleting materia" << std::endl;
		delete _inventory[idx];
	}

	_inventory[idx] = NULL;
}

/*
 * Use a materia in a given slot on the target.
 * No-op for out-of-bounds or empty slots.
 */
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "[Character] use failed (slot " << idx << ")" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
