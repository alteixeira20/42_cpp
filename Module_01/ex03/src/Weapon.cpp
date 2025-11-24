#include "Weapon.hpp"

// CONSTRUCTOR
// 	- Uses an *initializer list* to set the value of _type.
// 	- In C++, member variables are initialized BEFORE the constructor body runs.
// 		- Using ": _type(type)" initializes the string directly with the given value.
// 	- This avoids creating an empty string first and then assigning to it.

Weapon::Weapon(const std::string &type)
	: _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(const std::string &newType)
{
	_type = newType;
}
