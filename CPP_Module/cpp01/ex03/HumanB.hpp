#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "./Weapon.hpp"

class HumanB
{
private:
	Weapon *wp;
	std::string nameB;
public:
	void attack(void);
	void setWeapon(Weapon &weapon);
	HumanB(std::string nameH);
	~HumanB();
};



#endif