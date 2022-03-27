#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Form *shr = new ShrubberyCreationForm("sehyan");
		Bureaucrat A("HI", 10);
		A.signForm(*shr);
		shr->execute(A);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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