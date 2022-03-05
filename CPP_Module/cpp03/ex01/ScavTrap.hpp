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
};

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	std::cout << "ScavTrap Created" << std::endl;
}

ScavTrap::~ScavTrap()
{
}

#endif