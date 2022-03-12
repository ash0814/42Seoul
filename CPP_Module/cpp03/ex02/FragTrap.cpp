#include "./FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " Created" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(FragTrap &ft)
{
	*this = ft;
}

FragTrap &FragTrap::operator=(FragTrap &ft)
{
	name = ft.name;
	hitPoints = ft.hitPoints;
	energyPoints = ft.energyPoints;
	attackDamage = ft.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "highFive!" << std::endl;
}