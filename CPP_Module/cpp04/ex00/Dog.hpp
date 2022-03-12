#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"

class Dog : Animal
{
private:
	/* data */
public:
	Dog(/* args */);
	~Dog();
};

Dog::Dog(/* args */)
{
	type = "Dog";
}

Dog::~Dog()
{
}


#endif