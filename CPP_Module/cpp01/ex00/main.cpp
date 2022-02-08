#include "./Zombie.hpp"

int main(void)
{
	Zombie z;
	z.randomChump("zzz");
	z.~Zombie();
	Zombie a;
	a.randomChump("aaa");
	return (0);
}