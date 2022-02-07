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

	std::string checkStr(std::string str);

public:
	bool addInfo(void);
	void preview(void);
	void printAll(void);
	Contacts();
	~Contacts();
};
