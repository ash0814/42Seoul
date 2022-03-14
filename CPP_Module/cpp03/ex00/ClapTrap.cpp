#include "./ClapTrap.hpp"

void ClapTrap::attack(std::string target)
{
	std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take " << amount << " point of Damage" << std::endl;
	this->hitPoints  = std::max(hitPoints - (int)amount, 0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " is Repaired " << amount << " point" << std::endl;
	this->hitPoints += amount;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Clap Trap " << name << " Created" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl; 
}

ClapTrap::ClapTrap(ClapTrap &ct)
{
	*this = ct;
}

ClapTrap &ClapTrap::operator= (ClapTrap &ct)
{
	if (&ct != this)
	{
		this->name = ct.name;
		this->hitPoints = ct.hitPoints;
		this->energyPoints = ct.energyPoints;
		this->attackDamage = ct.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap has Broken" << std::endl;
}