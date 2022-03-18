#include "./Dog.hpp"

Dog::Dog()
{
	std::cout << "HI Puppy!" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Bye Puppy!" << std::endl;
}

Dog::Dog(const Dog &d)
{
	*this = d;
}

Dog &Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		type = d.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}