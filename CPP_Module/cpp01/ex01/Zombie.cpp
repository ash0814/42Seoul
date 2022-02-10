#include "./Zombie.hpp"

void Zombie::makeName(std::string name)
{
	_name = name;
}

void Zombie::announce(void)
{
	std::cout << "<" << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::Zombie() {
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}