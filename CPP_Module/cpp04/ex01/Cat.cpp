#include "./Cat.hpp"

Cat::Cat()
{
	std::cout << "I'm Kitty" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Bye Kitty!" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &c)
{
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
{
	if (this != &c)
	{
		type = c.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEWWWWWWW" << std::endl;
}