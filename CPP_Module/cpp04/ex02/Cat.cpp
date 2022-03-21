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
	brain = new Brain();
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
{
	if (this != &c)
	{
		type = c.type;
		delete this->brain;
		this->brain = new Brain();
		this->brain = c.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEWWWWWWW" << std::endl;
}

Brain *Cat::getBrain(void)
{
	return this->brain;
}