#include "./HumanB.hpp"
#include <iostream>

// 무기를 안들었을 때 attack() 하면
// 두주먹으로 친다!

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