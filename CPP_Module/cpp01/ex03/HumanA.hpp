#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &wp;
	std::string nameA;

public:
	void attack(void);
	HumanA(std::string nameH, Weapon &weapon);
	~HumanA();
};

#endif