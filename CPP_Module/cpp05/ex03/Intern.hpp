#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "./Form.hpp"

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