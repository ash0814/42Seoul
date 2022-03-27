#include "./Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Bureaucrat br("brName", 10);
	br.signForm(*rrf);
	br.executeForm(*rrf);
	delete rrf;
	return (0);
}