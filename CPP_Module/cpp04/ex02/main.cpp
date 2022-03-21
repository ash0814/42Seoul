
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	const Animal *meta = j;
	meta->makeSound();

	delete j;
	delete i;

	// int animal_cnt = 6;
	// std::cout << "--------[Constructors of List]--------" << std::endl;
	// Animal *list[animal_cnt];
	// for (int i = 0; i < animal_cnt; i++) {
	// 	if (i % 2 == 0)
	// 		list[i] = new Dog();
	// 	else
	// 		list[i] = new Cat();
	// 	std::cout << std::endl;
	// }
	// for (int i = 0; i < animal_cnt; i++) {
	// 	list[i]->makeSound();
	// }

	// std::cout << "\n--------[Destructors of List]--------" << std::endl;
	// for (int i = 0; i < animal_cnt; i++) {
	// 	delete list[i];
	// }
	return (0);
}
