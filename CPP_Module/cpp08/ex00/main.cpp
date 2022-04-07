#include "./easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(5, 10);
	v.push_back(10);
	v.push_back(12);
	v.push_back(14);
	v.push_back(15);

	try
	{
		easyfind(v, 12);
		std::cout << "find!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(v, 20);
		std::cout << "find!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}