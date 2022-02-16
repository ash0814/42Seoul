#include "./HumanB.hpp"
#include <iostream>

void HumanB::attack(void)
{
	std::cout << nameB << " attacks with his " << wp->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	wp = &weapon;
}

HumanB::HumanB(std::string nameH)
{
	nameB = nameH;
	wp = NULL;
}

HumanB::~HumanB()
{
}