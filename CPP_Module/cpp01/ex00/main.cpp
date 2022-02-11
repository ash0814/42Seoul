#include "./Zombie.hpp"

int main(void)
{
	randomChump("random");
	Zombie *nz = newZombie("new Zombie");
	nz->announce();
	delete nz;
	return (0);
}