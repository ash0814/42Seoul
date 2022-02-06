# include "Contacts.hpp"

bool Contacts::addInfo(void)
{
	std::cout << "first name : ";
	if (!std::getline(std::cin, firstName))
		return (false);
	std::cout << "last name : ";
	if (!std::getline(std::cin,lastName))
		return (false);
	std::cout << "nick name : ";
	if (!std::getline(std::cin, nickName))
		return (false);
	std::cout << "phone number : ";
	if (!std::getline(std::cin, phoneNumber))
		return (false);
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, darkestSecret))
		return (false);
	return (true);
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
