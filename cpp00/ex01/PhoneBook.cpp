#include "./PhoneBook.hpp"

void PhoneBook::addFirstName(int idx) 
{
	std::cout << "first name : ";
	std::cin >> firstName[idx];
}

void PhoneBook::printName(void)
{
	std::cout << "===" << std::endl;
	for (int i = 0; i < getIdx(); i++)
		std::cout << firstName[i] << std::endl;
}

int PhoneBook::getIdx(void)
{
	int i = 0;
	while (!firstName[i].empty())
		i++;
	return i;
}

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}