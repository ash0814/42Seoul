#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zb;

	zb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string zbname = name + " " + static_cast<char>(i + 1 + '0');
		zb[i].makeName(zbname);
		zb[i].announce();
	}
	return zb;
}