
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_CNT 10;

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	const Animal *list[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			list[i] = new Dog();
		else
			list[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		delete list[i];
		std::cout << std::endl;
	}

	const Dog d;
	const Cat c;
	d.makeSound();
	c.makeSound();

	return (0);
}