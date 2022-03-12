#include "./ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " Created" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap()
{
}

ScavTrap::ScavTrap(ScavTrap &st)
{
	*this = st;
}

ScavTrap &ScavTrap::operator=(ScavTrap &st)
{
	this->name = st.name;
	this->hitPoints = st.hitPoints;
	this->energyPoints = st.energyPoints;
	this->attackDamage = st.attackDamage;
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