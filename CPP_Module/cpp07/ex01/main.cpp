#include "./iter.hpp"


int main()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	std::string str[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

	iter(a, 10, print);
	std::cout << std::endl;
	iter(str, 7, print);
	return (0);
}