#include "./ClapTrap.hpp"

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take " << amount << " point of Damage" << std::endl;
	this->energyPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " is Repaired " << amount << " point" << std::endl;
	this->energyPoints += amount;
}

ClapTrap::ClapTrap(std::string const & name) : name(name)
{
	std::cout << "Clap Trap Created" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Broken" << std::endl;
}