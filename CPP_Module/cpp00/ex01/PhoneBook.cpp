# include "PhoneBook.hpp"

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
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout<< std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "nick Name" << std::endl;
	for (int i = 0; i < len; i++) {
		std::cout << std::setw(10) << i << "|";
		contacts[i].preview();
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

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}
