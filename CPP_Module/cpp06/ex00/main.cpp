#include "./Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "argument Error" << std::endl;
		return (0);
	}
	Convert cvt(argv[1]);

	cvt.printChar();
	cvt.printInt();
	cvt.printFloat();
	cvt.printDouble();

	return (0);
}