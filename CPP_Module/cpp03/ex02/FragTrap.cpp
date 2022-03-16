#include "./FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap " << name << " Created" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor Created" << std::endl;
}

FragTrap::FragTrap(FragTrap &ft)
{
	*this = ft;
}

FragTrap &FragTrap::operator=(FragTrap &ft)
{
	if (&ft != this)
	{
		name = ft.name;
		hitPoints = ft.hitPoints;
		energyPoints = ft.energyPoints;
		attackDamage = ft.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< name << " has Broken" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "highFive!" << std::endl;
}

void FragTrap::attack(std::string target)
{
	std::cout << "FragTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}