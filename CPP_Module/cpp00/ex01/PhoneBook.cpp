# include "PhoneBook.hpp"

bool PhoneBook::addContacts()
{
	Contacts ct;

	if (!ct.addInfo())
		return (false);
	contacts[idx % 8] = ct;
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
	int i = -1;

	std::cout << "Enter Index (0~7 | EXIT) : ";
	while (true)
	{
		if (!std::getline(std::cin, index))
			return (false);
		if (index == "exit" || index == "EXIT")
			break;
		if (index.length() != 1) {
			std::cout << "Error!\nEnter Index (0~7 | EXIT) : ";
			continue;
		}
		i = index[0] - '0';
		if (i > 7 || i < 0) {
			std::cout << "Error!\nEnter Index (0~7 | EXIT) : ";
			continue;
		}
		break;
	}
	if (i != -1)
		this->contacts[i].printAll(); 
	return (true);
}

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}
