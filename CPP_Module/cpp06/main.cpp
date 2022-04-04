#include "./Convert.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	Convert cvt(argv[1]);

	// float a = 2.f;
	cvt.printChar();
	cvt.printInt();
	cvt.printFloat();
	cvt.printDouble();

	return (0);
}