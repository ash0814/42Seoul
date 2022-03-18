#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal created" << std::endl;
	type = "wrong";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	*this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	if (&a != this)
	{
		type = a.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal BYE!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}


