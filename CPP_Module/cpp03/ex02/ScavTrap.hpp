#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(ScavTrap &st);
	ScavTrap &operator=(ScavTrap &st);
	~ScavTrap();
	void guardGate();
};


#endif