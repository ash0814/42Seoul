#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(ScavTrap &st);
	ScavTrap &operator=(ScavTrap &st);
	~ScavTrap();

	void guardGate();
	void attack(std::string target);
};


#endif