#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm shr("Home");
		Bureaucrat A("sehyan", 10);
		A.signForm(shr);
		A.executeForm(shr);
	}
	catch(const std::exception& e)
	{
		std::cout << "Form Creation Fail because " << e.what() << std::endl;
	}
	std::cout << "\n======\n" << std::endl;
	try
	{
		srand((unsigned int)time(NULL));
		Form *robot = new RobotomyRequestForm("RRbot");
		Form *AAbot = new RobotomyRequestForm("AAbot");
		Bureaucrat B("BBB", 10);
		B.signForm(*robot);
		B.signForm(*AAbot);
		robot->execute(B);
		AAbot->execute(B);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n======\n" << std::endl;
	try
	{
		Form *presi = new PresidentialPardonForm("pardonForm");
		Bureaucrat P("President", 1);
		P.signForm(*presi);
		presi->execute(P);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}