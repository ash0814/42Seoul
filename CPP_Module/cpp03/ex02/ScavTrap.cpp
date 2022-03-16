#include "./ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap " << name << " Created" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor Created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &st)
{
	*this = st;
}

ScavTrap &ScavTrap::operator=(ScavTrap &st)
{
	if (&st != this)
	{
		this->name = st.name;
		this->hitPoints = st.hitPoints;
		this->energyPoints = st.energyPoints;
		this->attackDamage = st.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has Broken" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string target)
{
	std::cout << "ScavTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}