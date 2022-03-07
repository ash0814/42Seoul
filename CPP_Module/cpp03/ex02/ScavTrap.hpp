#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : ClapTrap
{
private:
	/* data */
public:
	ScavTrap(std::string const & name);
	~ScavTrap();
	void guardGate();
};


#endif