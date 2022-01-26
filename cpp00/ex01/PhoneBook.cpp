#include "./PhoneBook.hpp"

void PhoneBook::addInfo(int idx) 
{
	std::cout << "first name : ";
	std::cin >> firstName[idx];
	std::cout << "last name : ";
	std::cin >> lastName[idx];
	std::cout << "nick name : ";
	std::cin >> nickName[idx];
	std::cout << "phone number : ";
	std::cin >> phoneNumber[idx];
	std::cout << "darkest secret : ";
	std::cin >> darkestSecret[idx];
}

void PhoneBook::printName(void)
{
	std::cout << "===" << std::endl;
	for (int i = 0; i < getIdx(); i++){
		std::cout.width(10);
		std::cout << firstName[i] << " | " << lastName[i] << " | " << nickName[i]
		<< " | " << phoneNumber[i] << " | " << darkestSecret[i] <<  std::endl;
	}
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