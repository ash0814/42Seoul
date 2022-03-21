
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const Animal meta;
	std::cout << std::endl;
	meta.makeSound();
	std::cout << std::endl;
	delete j;
	delete i;

	int animal_cnt = 6;
	std::cout << "--------[Constructors of List]--------" << std::endl;
	Animal *list[animal_cnt];
	for (int i = 0; i < animal_cnt; i++) {
		if (i % 2 == 0)
			list[i] = new Dog();
		else
			list[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < animal_cnt; i++) {
		list[i]->makeSound();
	}

	std::cout << std::endl;

	Dog *dg = new Dog();
	dg->getBrain()->setIdea("dg_idea");
	*(Dog *)list[0] = *dg;
	delete dg;
	std::cout << "******** > " << ((Dog *)list[0])->getBrain()->getIdea(10) <<std::endl;

	Dog nd = *(Dog *)list[0];
	((Dog *)list[0])->getBrain()->setIdea("new_set_idea");
	std::cout << "******** > " << ((Dog *)list[0])->getBrain()->getIdea(10) <<std::endl;
	std::cout << "******** > " << nd.getBrain()->getIdea(10) <<std::endl;


	std::cout << "\n--------[Destructors of List]--------" << std::endl;
	for (int i = 0; i < animal_cnt; i++) {
		delete list[i];
	}
	return (0);
}
