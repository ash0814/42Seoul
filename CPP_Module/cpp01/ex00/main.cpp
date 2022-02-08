#include "./Zombie.hpp"

int main(void)
{
	Zombie z;
	z.randomChump("Day6");
	z.~Zombie();
	return (0);
}