#include "./Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *zb = new Zombie;

	(*zb)._name = name;
	return zb;
}