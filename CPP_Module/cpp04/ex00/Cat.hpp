#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat(/* args */);
	~Cat();
	void makeSound();
};

void Cat::makeSound()
{
	std::cout << "MEWWWWWWW" << std::endl;
}

Cat::Cat(/* args */)
{
	std::cout << "Kitty cutty" << std::endl;
}

Cat::~Cat()
{
}


#endif