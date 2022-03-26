#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("noname", false, 145, 137)
{
	std::cout << "create type: Shrubbery, name: noname, sign: "<< this->getRights() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) 
: Form(_name, false, 145, 137)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) 
: Form(scf.getName(), scf.getRights() , 145, 137)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	this->setRights(scf.getRights());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Delete type: Shrubbery, name: " << this->getName() << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getRights() != true) {
		throw HaveNoSign();
	} else {
		if (this->getExecGrade() >= executor.getGrade()) {
			//executor, ascii tree 만들기
			
			std::cout << "Form <" << this->getName() << "> executing..." << std::endl;
		} else {
			throw GradeTooLowException();
		}
	}
}