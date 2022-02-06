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
	bool addContacts();
	void printPreview(void);
	bool printContacts(void);
	int getIdx(void);
	PhoneBook(/* args */);
	~PhoneBook();
};
