#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm shr("Home");
		Bureaucrat A("sehyan", 150);
		A.signForm(shr);
		A.executeForm(shr);
	}
	catch(const std::exception& e)
	{
		std::cout << "Form Creation Fail because " << e.what() << std::endl;
	}
	// try
	// {
	// 	Form *robot = new RobotomyRequestForm("RRbot");
	// 	Form *AAbot = new RobotomyRequestForm("AAbot");
	// 	Bureaucrat B("BBB", 10);
	// 	B.signForm(*robot);
	// 	B.signForm(*AAbot);
	// 	robot->execute(B);
	// 	AAbot->execute(B);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// try
	// {
	// 	Form *presi = new PresidentialPardonForm("pardonForm");
	// 	Bureaucrat P("President", 1);
	// 	P.signForm(*presi);
	// 	presi->execute(P);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return (0);
}