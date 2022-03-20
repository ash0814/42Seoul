#include "./Dog.hpp"

Dog::Dog()
{
	std::cout << "HI Puppy!" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Bye Puppy!" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &d)
{
	*this = d;
}

Dog &Dog::operator=(const Dog &d)
{
	type = d.type;
	if (this->brain)
	{
		delete this->brain;
		this->brain = NULL;
	}
	this->brain = new Brain();
	this->brain = d.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}