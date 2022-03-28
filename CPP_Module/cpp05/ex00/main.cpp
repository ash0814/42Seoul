#include "./Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("sehyan", 1);
		b.decrementGrade(20);
		std::cout << b << std::endl;
		b.incrementGrade(1);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat Fail : " << e.what() << '\n';
	}

	try
	{
		Bureaucrat a("aaaaa", 149);
		a.decrementGrade(1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat Fail : " << e.what() << '\n';
	}

	return (0);
}