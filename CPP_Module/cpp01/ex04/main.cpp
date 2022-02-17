#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string rpFileName;
	if (argc != 4 || !argv[2][0] || !argv[3][0]) {
		std::cout << "Input Error" << std::endl;
		return (1);
	}
	std::string origin = argv[2];
	std::string change = argv[3];
	ifs.open(argv[1]);
	rpFileName = argv[1];
	rpFileName += ".replace";
	ofs.open(rpFileName);
	while (ifs.peek() != EOF)
	{
		std::string line;
		std::getline(ifs, line);
		size_t resFind;
		resFind = line.std::string::find(origin, 0);
		while ((int)resFind != -1)
		{
			for (int i = 0; i < (int)change.length(); i++) {
				line[resFind++] = change[i];
			}
			resFind = line.std::string::find(origin, 0);
		}
		ofs << line << "\n";
	}
	return (0);
}