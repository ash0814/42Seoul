#include "./Zombie.hpp"

int main(void)
{
	randomChump("random");
	Zombie *nz = newZombie("day6");
	nz->announce();
	nz->~Zombie();
	return (0);
}