#include "./Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *z = new Zombie(name);
	z->announce();
	z->~Zombie();
}