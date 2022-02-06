# include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		if (!std::getline(std::cin, cmd))
			return (1);
		if (cmd == "ADD" || cmd == "add") {
			if (!pb.addContacts())
				return (0);
		} else if (cmd == "SEARCH" || cmd == "search") {
			pb.printPreview();
			if (!pb.printContacts())
				return (0);
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