# include "PhoneBook.hpp"

int getCmd(Cmd *cmd)
{
	std::string command;

	if (!std::getline(std::cin, command))
		return (1);
	if (!command.compare("ADD") || !command.compare("add"))
		*cmd = ADD;
	else if (!command.compare("SEARCH") || !command.compare("search"))
		*cmd = SEARCH;
	else if (!command.compare("EXIT") || !command.compare("exit"))
		*cmd = EXIT;
	else
		*cmd = ERROR;
	return (0);
}

int main(void)
{
	PhoneBook pb;
	Contacts ct;
	Cmd cmd;

	// ct.addInfo();
	// pb.addContacts(ct, pb.getIdx());
	// pb.printContacts();
	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		if (getCmd(&cmd))
			break;
		switch (cmd)
		{
		case (ADD):
			std::cout << "ADD" << std::endl;
			if (!ct.addInfo()) {
				std::cout << "input Error" << std::endl;
			}
			pb.addContacts(ct, pb.getIdx());
			break;
		case (SEARCH):
			std::cout << "SEARCH" << std::endl;
			pb.printContacts();
			break;
		case (EXIT):
			std::cout << "EXIT" << std::endl;
			return (0);
		default:
			std::cout << "Command Error" << std::endl;
			break;
		}
	}
	return (0);

}