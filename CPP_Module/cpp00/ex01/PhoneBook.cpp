# include "PhoneBook.hpp"

bool PhoneBook::addContacts()
{
	Contacts ct;

	if (!ct.addInfo())
	{
		// std::cout << "\nInput Error" << std::endl;
		return (false);
	}
	contacts[getIdx()] = ct;
	idx++;
	return true;
}

void PhoneBook::printPreview(void)
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

bool PhoneBook::printContacts(void)
{
	std::string index;


}

int PhoneBook::getIdx(void)
{
	return idx;
}

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}
