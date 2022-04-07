#include "./easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

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
		std::cout << "Success!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}

	try
	{
		easyfind(v, 20);
		std::cout << "find!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}

	std::deque<char> dq(10);
	dq.push_back('a');
	dq.push_back('b');
	dq.push_back('c');
	dq.push_back('d');

	try
	{
		easyfind(dq, 'a');
		std::cout << "find!" << std::endl;
		easyfind(dq, 'e');
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}
	return (0);
}