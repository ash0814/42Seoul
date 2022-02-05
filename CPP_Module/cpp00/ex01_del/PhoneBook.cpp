#include "./PhoneBook.hpp"
#include <unistd.h>

int PhoneBook::addInfo(int i) 
{
	i = i % 8;
	std::cout << "first name : ";
	if (!std::getline(std::cin, firstName[i]))
		return (1);
	std::cout << "last name : ";
	if (!std::getline(std::cin,lastName[i]))
		return (1);
	std::cout << "nick name : ";
	if (!std::getline(std::cin, nickName[i]))
		return (1);
	std::cout << "phone number : ";
	if (!std::getline(std::cin, phoneNumber[i]))
		return (1);
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, darkestSecret[i]))
		return (1);
	return (0);
}

void PhoneBook::plusIdx(void)
{
	idx++;
}

std::string PhoneBook::checkStr(std::string str)
{
	std::string ret;

	if (str.length() <= 10) {
		ret = str;
	} else {
		str[9] = '.';
		for (int i = 10; i < (int)str.length(); i++)
			str[i] = '\0';
		ret = str;
	}
	return ret;
}

void PhoneBook::printName(void)
{
	int index = getIdx();

	if (index >= 8)
		index = 8;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout<< std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "nick Name" << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << checkStr(firstName[i]) << "|";
		std::cout << std::setw(10) << checkStr(lastName[i]) << "|";
		std::cout << std::setw(10) << checkStr(nickName[i]) << std::endl;
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

PhoneBook::PhoneBook()
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}