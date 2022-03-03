#include "./ClapTrap.hpp"

int main()
{
	ClapTrap A("ET");
	
	A.attack("DEVIL");
	A.takeDamage(5);
	A.beRepaired(30);
	return (0);
}