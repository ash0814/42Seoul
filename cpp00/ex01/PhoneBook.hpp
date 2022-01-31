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
	std::string firstName[8];
	std::string lastName[8];
	std::string nickName[8];
	std::string phoneNumber[8];
	std::string darkestSecret[8];
	int			idx;
public:
	void addInfo(int i);
	void printName(void);
	int getIdx(void);
	void plusIdx(void);
	void printIdxInfo(int i);
	PhoneBook();
	~PhoneBook();
};

