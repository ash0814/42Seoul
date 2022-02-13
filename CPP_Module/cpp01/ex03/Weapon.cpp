#include "./Weapon.hpp"

const std::string& Weapon::getType(void) const
{
	const std::string &typeREF = _type;
	return typeREF;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "setType : " << _type << std::endl;
}

Weapon::Weapon(const char *weaponType)
{
	_type = weaponType;
}

Weapon::~Weapon()
{
}