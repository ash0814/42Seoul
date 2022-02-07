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
	bool printContacts(void);
	bool addContacts();
	void printPreview(void);
	PhoneBook();
	~PhoneBook();
};
