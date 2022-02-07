# include "PhoneBook.hpp"

bool PhoneBook::addContacts()
{
	Contacts ct;

	if (!ct.addInfo())
		return (false);
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
	int idx = -1;

	std::cout << "Enter Index (0~7) : ";
	while (1)
	{
		if (!std::getline(std::cin, index))
			return (false);
		if (index == "exit" || index == "EXIT")
			break;
		if (index.length() != 1) {
			std::cout << "Error!\nEnter Index (0~7) : ";
			continue;
		}
		idx = index[0] - '0';
		if (idx > 7 || idx < 0) {
			std::cout << "Error!\nEnter Index (0~7) : ";
			continue;
		}
		break;
	}
	if (idx != -1)
		this->contacts[idx].printAll(); 
	return (true);
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
