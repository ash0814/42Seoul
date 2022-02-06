# include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	Contacts ct;
	std::string cmd;

	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		if (!std::getline(std::cin, cmd))
			return (1);
		if (cmd == "ADD" || cmd == "add") {
			std::cout << "ADD" << std::endl;
			if (ct.addInfo()) {
				std::cout << "input Error" << std::endl;
			}
			pb.addContacts(ct, pb.getIdx());
		} else if (cmd == "SEARCH" || cmd == "search") {
			std::cout << "SEARCH" << std::endl;
			pb.printContacts();
		} else if (cmd == "EXIT" || cmd == "exit") {
			std::cout << "EXIT" << std::endl;
			return (0);
		} else {
			std::cout << "Command Error" << std::endl;
			continue;
		}
	}
	return (0);
}