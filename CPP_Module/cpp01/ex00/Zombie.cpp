#include "./Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << "<" << _name << ">" << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is dead" << std::endl;
}