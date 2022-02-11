#include "./HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << HumanName << " attacks with his " << _wp.getType() << std::endl;
}

void HumanA::setType(Weapon &wp)
{
	std::cout << "setType : " << wp.getType() << std::endl;
}

HumanA::HumanA(const char *name, Weapon &wp) : HumanName(name), _wp(wp)
{
	setType(_wp);
}

HumanA::~HumanA()
{
}