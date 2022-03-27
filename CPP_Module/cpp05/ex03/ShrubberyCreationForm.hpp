#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./Form.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _name);
	ShrubberyCreationForm(const ShrubberyCreationForm &scf);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scf);

	void execute(Bureaucrat const & executor) const;
	void action() const;
};



#endif