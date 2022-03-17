#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap();
	~FragTrap();
	FragTrap(FragTrap &ft);
	FragTrap &operator=(FragTrap &ft);
	void highFivesGuys(void);
	void attack(std::string target);
};



#endif