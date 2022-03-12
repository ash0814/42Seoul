#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap A("CT");
	ScavTrap B("HIHI");
	FragTrap C("FRAG");


	A.attack("DEVIL");
	A.takeDamage(5);
	A.beRepaired(30);

	B.guardGate();
	B.guardGate();
	
	C.highFivesGuys();
	return (0);
}