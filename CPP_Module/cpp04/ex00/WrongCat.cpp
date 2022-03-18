#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Wrong Animal created" << std::endl;
	type = "wrong";
}

WrongCat::WrongCat(const WrongCat &a)
{
	*this = a;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
	if (&a != this)
	{
		type = a.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Animal BYE!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Sound" << std::endl;
}


