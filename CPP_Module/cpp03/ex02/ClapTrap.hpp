#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	const std::string &name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string const & name);
	~ClapTrap();
};



#endif