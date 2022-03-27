#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("noname", false, 25, 5)
{
	std::cout << "create type: Shrubbery, name: noname, sign: "<< this->getRights() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name) 
: Form(_name, false, 25, 5)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &scf) 
: Form(scf.getName(), scf.getRights() , 25, 5)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &scf)
{
	this->setRights(scf.getRights());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Delete type: Shrubbery, name: " << this->getName() << std::endl;
}

void PresidentialPardonForm::action() const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getRights() != true) {
		throw HaveNoSign();
	} else {
		if (this->getExecGrade() >= executor.getGrade()) {
			std::cout << "Form <" << this->getName() << "> executing..." << std::endl;
			this->action();
		} else {
			throw GradeTooLowException();
		}
	}
}