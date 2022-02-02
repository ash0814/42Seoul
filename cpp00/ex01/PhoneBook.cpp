#include "./PhoneBook.hpp"
#include <unistd.h>

void PhoneBook::addInfo(int i) 
{
	i = i % 8;
	std::cout << "first name : ";
	std::getline(std::cin, firstName[i]);
	std::cout << "last name : ";
	std::getline(std::cin,lastName[i]);
	std::cout << "nick name : ";
	std::getline(std::cin,nickName[i]);
	std::cout << "phone number : ";
	std::getline(std::cin,phoneNumber[i]);
	std::cout << "darkest secret : ";
	std::getline(std::cin,darkestSecret[i]);
}

void PhoneBook::plusIdx(void)
{
	idx++;
}

void PhoneBook::printName(void)
{
	int index = getIdx();

	if (index >= 8)
		index = 8;
	std::cout << std::setw(10) << std::right << "Index" << "|" 
		<< std::setw(10) << std::right << "First Name" << "|" <<
		std::setw(10) << std::right << "Last Name" << "|" << std::setw(10) << std::right 
		<< "nick Name" << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << std::setw(10) << std::right 
		<< i << "|" << std::setw(10) << std::right << firstName[i] << "|" <<
		std::setw(10) << std::right << lastName[i] << "|" << std::setw(10) << std::right 
		<< nickName[i] << std::endl;
	}
}

void PhoneBook::printIdxInfo(int i)
{
	i = i % 8;
	
	std::cout <<"Fist Name : " << firstName[i] << "\n" << "Last Name : " << lastName[i] << "\n" 
		<< "Nick Name : " << nickName[i] << "\n" << "Phone Number : " << phoneNumber[i] << "\n" 
		<< "Darkest Secret : " << darkestSecret[i] <<  std::endl;
}

int PhoneBook::getIdx(void)
{
	int i;

	i = idx;
	return i;
}

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}