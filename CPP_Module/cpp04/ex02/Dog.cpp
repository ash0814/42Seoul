#include "./Dog.hpp"

Dog::Dog()
{
	std::cout << "I'm Puppy!" << std::endl;
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
	brain = new Brain();
	*this = d;
}

Dog &Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		type = d.type;
		delete this->brain;
		this->brain = new Brain();
		*this->brain = *d.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

Brain *Dog::getBrain(void)
{
	return this->brain;
}
