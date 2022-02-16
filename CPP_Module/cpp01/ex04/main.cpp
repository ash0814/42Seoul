#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::string a;
	std::string b;
	std::ifstream ifs;
	std::ofstream ofs;

	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Input Error" << std::endl;
		return (1);
	}
	a = argv[2];
	b = argv[3];
	ifs.open(argv[1]);
	if (ifs.is_open())
	{
		ofs.open("replace");
		char c;
		std::string str;
		while (ifs.get(c))
		{
			str += c;
		}
		// size_t n = str.std::string::find(argv[2], 0);
		// str.substr(n);
		if (ofs.is_open())
			ofs.write(str.c_str(), str.length());
	}
	else
	{
		std::cout << "Open Error" << std::endl;
		return (1);
	}
	ifs.close();
	return (0);
}