#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	std::string firstName[8];
	std::string lastName[8];
	std::string nickName[8];
	std::string phoneNumber[8];
	std::string darkestSecret[8];
public:
	void addFirstName(std::string str,int idx);
	PhoneBook();
	~PhoneBook();
};

