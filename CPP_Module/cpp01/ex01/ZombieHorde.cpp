#include "./Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zb;

	if (N <= 0)
		return NULL;
	zb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string zbname = name + " ";
		std::stringstream ss;
		ss << i + 1;
		zbname += ss.str();
		zb[i].makeName(zbname);
		zb[i].announce();
	}
	return zb;
}