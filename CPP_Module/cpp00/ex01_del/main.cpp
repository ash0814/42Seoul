#include "./PhoneBook.hpp"

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
	Cmd cmd;
	int searchIdx;

	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		if (getCmd(&cmd))
			break;
		switch (cmd)
		{
		case (ADD):
			if (pb.addInfo(pb.getIdx()))
				return (0);
			pb.plusIdx();
			break;
		case (SEARCH):
			pb.printName();
			std::cout << "Enter Search Index : ";
			std::cin >> searchIdx;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			}
			std::cin.ignore(32767, '\n');
			pb.printIdxInfo(searchIdx);
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
