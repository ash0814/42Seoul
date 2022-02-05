# include "PhoneBook.hpp"

int Contacts::addInfo(void)
{
	std::cout << "first name : ";
	if (!std::getline(std::cin, firstName))
		return (1);
	std::cout << "last name : ";
	if (!std::getline(std::cin,lastName))
		return (1);
	std::cout << "nick name : ";
	if (!std::getline(std::cin, nickName))
		return (1);
	std::cout << "phone number : ";
	if (!std::getline(std::cin, phoneNumber))
		return (1);
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, darkestSecret))
		return (1);
	return (0);
}

void Contacts::printStr(void)
{
	std::cout << firstName << std::endl;
	std::cout << lastName << std::endl;
	std::cout << nickName << std::endl;
}

void PhoneBook::addContacts(Contacts ct, int i)
{
	contacts[i] = ct;
	idx++;
}

void PhoneBook::printContacts(void)
{
	int len;

	if (idx >= 8)
		len = 8;
	else
		len = idx;
	for (int i = 0; i < len; i++) {
		std::cout << "[" << i << "] : ";
		contacts[i].printStr();
	}
}

int PhoneBook::getIdx(void)
{
	return idx;
}

void PhoneBook::plusIdx(void)
{
	idx++;
}

Contacts::Contacts(/* args */)
{
}

Contacts::~Contacts()
{
}

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}
