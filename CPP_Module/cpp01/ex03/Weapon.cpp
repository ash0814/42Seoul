#include "./Weapon.hpp"

const std::string &Weapon::getType(void)
{
	std::string &ret = type;
	return (ret);
}

void Weapon::setType(std::string typeName)
{
	type = typeName;
}

Weapon::Weapon(std::string typeName)
{
	setType(typeName);
}

Weapon::~Weapon()
{
}
