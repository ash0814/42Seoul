# include <iostream>
# include <string>
# include <iomanip>
# include "Contacts.hpp"

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
