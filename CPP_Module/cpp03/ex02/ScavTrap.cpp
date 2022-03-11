#include "./ScavTrap.hpp"


ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	std::cout << "ScavTrap Created" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap has Broken" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}