#include "./PhoneBook.hpp"

void getCmd(Cmd *cmd)
{
	std::string command;
	// std::cin >> command;
	std::getline(std::cin, command);
	if (!command.compare("ADD") || !command.compare("add"))
		*cmd = ADD;
	else if (!command.compare("SEARCH") || !command.compare("search"))
		*cmd = SEARCH;
	else if (!command.compare("EXIT") || !command.compare("exit"))
		*cmd = EXIT;
	else
		*cmd = ERROR;
}

int main(void)
{
	PhoneBook pb;
	Cmd cmd;
	int searchIdx;

	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		getCmd(&cmd);

		switch (cmd)
		{
		case (ADD):
			pb.addInfo(pb.getIdx());
			pb.plusIdx();
			break;
		case (SEARCH):
			pb.printName();
			std::cout << "Enter Search Index : ";
			std::cin >> searchIdx;
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
	pb.printName();
	return (0);
}
