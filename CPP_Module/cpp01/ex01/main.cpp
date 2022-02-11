#include "./Zombie.hpp"

int main(void)
{
	Zombie *main;
   
	main = zombieHorde(5, "zombie");
	delete[] main;
	return (0);
}