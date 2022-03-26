#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("noname", false, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : Form(_name, false, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
{
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}