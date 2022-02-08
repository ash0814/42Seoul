#include "./Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie *zb = newZombie(name);
	(*zb).announce();
}