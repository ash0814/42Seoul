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
	type = c.type;
	if (this->brain != NULL)
	{
		delete this->brain;
		this->brain = NULL;
	}
	this->brain = new Brain();
	this->brain = c.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEWWWWWWW" << std::endl;
}