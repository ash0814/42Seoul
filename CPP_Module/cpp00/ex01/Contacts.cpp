# include "Contacts.hpp"

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

std::string Contacts::checkStr(std::string str)
{
	std::string ret;

	if (str.length() <= 10) {
		ret = str;
	} else {
		ret = str.substr(0, 10);
		ret[9] = '.';
	}
	return ret;
}

void Contacts::preview(void)
{
	std::cout << std::setw(10) << checkStr(firstName) << "|";
	std::cout << std::setw(10) << checkStr(lastName) << "|";
	std::cout << std::setw(10) << checkStr(nickName) << std::endl;
}

Contacts::Contacts(/* args */)
{
}

Contacts::~Contacts()
{
}
