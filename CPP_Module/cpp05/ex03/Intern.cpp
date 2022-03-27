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
	return *this;
}

Form *Intern::makeForm(std::string a, std::string b)
{

}