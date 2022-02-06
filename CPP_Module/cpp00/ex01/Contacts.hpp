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
	bool addInfo(void);
	void preview(void);
	std::string checkStr(std::string str);
	Contacts(/* args */);
	~Contacts();
};
