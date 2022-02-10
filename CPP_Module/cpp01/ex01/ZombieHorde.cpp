#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zb;
	zb = &(new Zombie(name))[N];
	for (int i = 0; i < N; i++)
	{
		zb[i].announce();
	}
	return zb;
}