#include "./HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << HumanName << " attacks with his " << _wp.getType() << std::endl;
}

HumanA::HumanA(const char *name, Weapon &wp) : HumanName(name), _wp(wp)
{
}

HumanA::~HumanA()
{
}