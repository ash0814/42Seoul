#include "./Zombie.hpp"

int main(void)
{
	Zombie *main;
   
	main = zombieHorde(132, "zombie");
	delete[] main;
	return (0);
}