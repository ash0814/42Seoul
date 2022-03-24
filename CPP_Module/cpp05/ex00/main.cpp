#include "./Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("sehyan", 1);
		b.incrementGrade(1);
		std::cout << b << std::endl;
		b.decrementGrade(20);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat a("aaaaa", 149);
		a.decrementGrade(1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}