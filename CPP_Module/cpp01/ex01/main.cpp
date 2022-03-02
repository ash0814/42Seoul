#include "./Zombie.hpp"

void foo(void)
{
	Zombie *zh1;
	Zombie *zh2;
	Zombie *zh3;

	zh1 = zombieHorde(-3, "zombie");
	zh2 = zombieHorde(0, "zombie");
	zh3 = zombieHorde(10, "zombie");
	delete[] zh3;
}

int main(void)
{
	foo();
	return (0);
}
