#include "./Weapon.hpp"

const std::string& Weapon::getType(void) const
{
	const std::string &typeREF = _type;
	return typeREF;
}

void Weapon::setType(const char *type)
{
	_type = type;
}

Weapon::Weapon(const char *weaponType)
{
	_type = weaponType;
}

Weapon::~Weapon()
{
}