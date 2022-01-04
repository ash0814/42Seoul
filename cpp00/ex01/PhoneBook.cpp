#include <iostream>

int main(void)
{
	while (1) {
		std::string cmd;
		std::cin >> cmd;
		if (cmd.compare("EXIT") == 0) {
			return (0);
		} else if (cmd.compare("ADD") == 0) {
			std::cout << "input ADD" << std::endl;
		} else if (cmd.compare("SEARCH") == 0) {
			std::cout << "input SEARCH" << std::endl;
		} else {
			continue;
		}
	}
	return (0);
}