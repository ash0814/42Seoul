#include "./Zombie.hpp"

int main(void)
{
	Zombie *nz = newZombie("new Zombie");
	Zombie a("aaaa");
	nz->announce();
	randomChump("randomChumpZombie");
	delete nz;
	return (0);
}
