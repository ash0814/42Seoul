#include "./Zombie.hpp"

int main(void)
{
	Zombie *main;
   
	main = zombieHorde(5, "zombie");
	for (int i = 0; i < 5; i++) {
		main[i].~Zombie();
	}
	return (0);
}