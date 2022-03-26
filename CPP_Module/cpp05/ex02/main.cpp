#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("sehyan", 10);
		// Form testForm("test", false, 15, 20);
		b.incrementGrade(1);
		std::cout << b << std::endl;
		// testForm.beSigned(b);
		// b.signForm(testForm);
		b.decrementGrade(20);
		std::cout << b << std::endl;
		// testForm.beSigned(b);
		// b.signForm(testForm);
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

		// Form ff("testError", false, 151, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}