#include "./Intern.hpp"

Intern::Intern()
{
	std::cout << "create Default Intern" << std::endl;
}

Intern::Intern(const Intern &i)
{
	*this = i;
}

Intern::~Intern()
{
	std::cout << "delete Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &i)
{
	(void) i;
	return *this;
}

Form *Intern::makeForm(std::string a, std::string b)
{
	std::string formNameList[3] = 
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	int formName = 0;

	for (; formName < 3; formName++) {
		if (a == formNameList[formName]){
			break;
		}
	}
	switch (formName)
	{
	case 0:
		return (new ShrubberyCreationForm(b));
	case 1:
		return (new RobotomyRequestForm(b));
	case 2:
		return (new PresidentialPardonForm(b));
	default:
		std::cout << "Wrong Form Name" << std::endl;
		return NULL;
	}
	return NULL;
}