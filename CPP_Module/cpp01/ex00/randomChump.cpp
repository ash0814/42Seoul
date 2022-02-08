#include "./Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie *zb;

	zb = new Zombie;
	zb->_name = name;
	zb->announce();
}