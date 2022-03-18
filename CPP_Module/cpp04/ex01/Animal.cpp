#include "./Animal.hpp"

Animal::Animal()
{
	std::cout << "What's this Amimal's type?" << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Bye!" << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
}

Animal &Animal::operator=(const Animal &a)
{
	if (&a != this)
	{
		type = a.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}