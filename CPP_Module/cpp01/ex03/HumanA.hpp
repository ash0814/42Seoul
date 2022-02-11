#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA
{
private:
	std::string HumanName;
	Weapon _wp;
public:
	void attack(void);
	void setType(Weapon &wp);
	HumanA(const char *name, Weapon &wp);
	~HumanA();
};

#endif