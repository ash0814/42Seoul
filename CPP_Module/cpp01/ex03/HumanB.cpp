#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << _name<< " attacks with his " << _wp->getType() << std::endl;
}

void HumanB::setWeapon(Weapon wp)
{
	_wp = &wp;
	std::cout << "setWeapon : " << wp.getType() << std::endl;
}

HumanB::HumanB(const char *name)
{
	_name = name;
	_wp = 0;
}

HumanB::~HumanB()
{
}