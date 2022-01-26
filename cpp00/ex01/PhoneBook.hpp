#include <iostream>
#include <iomanip>

enum Cmd
{
	ADD,
	SEARCH,
	EXIT,
	ERROR
};

class PhoneBook
{
private:
	std::string firstName[9];
	std::string lastName[9];
	std::string nickName[9];
	std::string phoneNumber[9];
	std::string darkestSecret[9];
public:
	void addInfo(int idx);
	void printName(void);
	int getIdx(void);
	PhoneBook();
	~PhoneBook();
};

