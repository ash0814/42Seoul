#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &d);
	Dog &operator=(const Dog &d);
	~Dog();

	Brain *getBrain(void);
	void makeSound() const;
};

#endif