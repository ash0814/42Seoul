#include "./PhoneBook.hpp"

void getCmd(Cmd *cmd)
{
	std::string command;
	std::cin >> command;
	if (command.compare("ADD") == 0)
		*cmd = ADD;
	else if (command.compare("SEARCH") == 0)
		*cmd = SEARCH;
	else if (command.compare("EXIT") == 0)
		*cmd = EXIT;
	else
		*cmd = ERROR;
}

int main(void)
{
	PhoneBook pb;
	Cmd cmd;
	while (1)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT) : ";
		getCmd(&cmd);

		switch (cmd)
		{
		case (ADD):
			pb.addInfo(pb.getIdx());
			break;
		case (SEARCH):
			std::cout << "SEARCH" << std::endl;
			break;
		case (EXIT):
			pb.printName();
			return (0);
		default:
			std::cout << "Command Error" << std::endl;
			break;
		}
	}
	pb.printName();
	return (0);
}
