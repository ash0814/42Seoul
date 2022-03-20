
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const Animal *list[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			list[i] = new Dog();
		else
			list[i] = new Cat();
	}

	delete j;
	delete i;
	return (0);
}