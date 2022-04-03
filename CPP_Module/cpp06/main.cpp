#include "./Convert.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	// std::string input = argv[1];
	Convert cvt(argv[1]);

	// int c = -42;
	// std::cout << "aaa : " << (char)c << std::endl;
	cvt.printChar();
	// cvt.printInt();
	// cvt.printFloat();
	// cvt.printDouble();

	return (0);
}