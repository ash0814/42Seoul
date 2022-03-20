#include "./Cat.hpp"

Cat::Cat()
{
	std::cout << "I'm Kitty" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Bye Kitty!" << std::endl;
}

Cat::Cat(const Cat &c)
{
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
{
	type = c.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEWWWWWWW" << std::endl;
}