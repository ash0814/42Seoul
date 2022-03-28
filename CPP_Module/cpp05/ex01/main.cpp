#include "./Bureaucrat.hpp"

int main()
{
	try
	{
		Form testForm("test", false, 15, 20);
		Bureaucrat b("sehyan", 10);
		b.incrementGrade(1);
		std::cout << b << std::endl;
		b.signForm(testForm);
		std::cout << std::endl;

		b.decrementGrade(20);
		std::cout << b << std::endl;
		b.signForm(testForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n=======\n";
	try
	{
		Form ff("testError", false, 151, 0);
		Bureaucrat A("aa", 100);

		A.signForm(ff);
	}
	catch (std::exception &e)
	{
		std::cout << "Create Fail because " << e.what() << std::endl;
	}

	return (0);
}