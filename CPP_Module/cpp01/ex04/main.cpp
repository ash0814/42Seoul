#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::string a;
	std::string b;
	std::ifstream ifs;

	if (argc != 4 || !argv[2][0] || !argv[3][0]) {
		std::cout << "Input Error" << std::endl;
		return (1);
	}
	a = argv[2];
	b = argv[3];
	ifs.open(argv[1], std::ifstream::in);
	if (ifs.is_open()) {
		while (!ifs.eof()) {
			char c;
			ifs.get(c);
			std::cout << c;
		}
	} else {
		std::cout << "Open Error" << std::endl;
		return (1);
	}
	ifs.close();
	return (0);
}