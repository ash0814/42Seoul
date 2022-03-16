#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	void attack(std::string target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	// void printState(void);

	ClapTrap(std::string name);
	ClapTrap();
	ClapTrap(ClapTrap &ct);
	ClapTrap &operator= (ClapTrap &ct);
	~ClapTrap();
};



#endif