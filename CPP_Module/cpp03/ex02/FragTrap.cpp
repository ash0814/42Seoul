#include "./FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap Created" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap()
{
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "highFive!" << std::endl;
}