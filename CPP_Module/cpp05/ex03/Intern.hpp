#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Intern(const Intern &i);
	~Intern();
	Intern &operator=(const Intern &i);

	Form *makeForm(std::string, std::string);
};



#endif