#include "./Convert.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	std::string input = argv[1];
	Convert cvt(input);
}