#include "ScavTrap.hpp"

int main()
{
	// ClapTrap A("ET");
	ScavTrap B("HI");

	B.guardGate();
	// B.printState();
	B.attack("DEVIL");
	B.takeDamage(5);
	// B.printState();
	B.beRepaired(30);
	// B.printState();
	return (0);
}