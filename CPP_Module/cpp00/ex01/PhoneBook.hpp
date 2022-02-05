# include <iostream>
# include <string>
# include <iomanip>

class Contacts
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	int addInfo(void);
	void printStr(void);
	Contacts(/* args */);
	~Contacts();
};


class PhoneBook
{
private:
	Contacts contacts[8];
	int idx;
public:
	void addContacts(Contacts ct, int i);
	void printContacts(void);
	int getIdx(void);
	void plusIdx(void);
	PhoneBook(/* args */);
	~PhoneBook();
};
