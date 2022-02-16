#include "./HumanA.hpp"
#include <iostream>

void HumanA::attack(void)
{
	std::cout << nameA << " attacks with his " << wp.getType() << std::endl;
}

HumanA::HumanA(std::string nameH, Weapon &weapon) : wp(weapon), nameA(nameH)
{
}

HumanA::~HumanA()
{
}