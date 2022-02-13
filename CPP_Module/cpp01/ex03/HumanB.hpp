#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_wp;
public:
	void setWeapon(Weapon wp);
	void attack(void);
	HumanB(const char *name);
	~HumanB();
};



#endif