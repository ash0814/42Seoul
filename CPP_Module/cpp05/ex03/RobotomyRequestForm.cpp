#include "./RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("noname", false, 72, 45)
{
	std::cout << "create type: Shrubbery, name: noname, sign: "<< this->getRights() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name) 
: Form(_name, false, 72, 45)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &scf) 
: Form(scf.getName(), scf.getRights() , 72, 45)
{
	std::cout << "create type: Shrubbery, name: " << this->getName() 
	<< ", sign: "<< this->getRights() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &scf)
{
	this->setRights(scf.getRights());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Delete type: Shrubbery, name: " << this->getName() << std::endl;
}

void RobotomyRequestForm::action() const
{
	srand((unsigned int)time(NULL));
	if (rand() % 2) {
		std::cout << this->getName() << " has been robotomized" << std::endl;
	} else {
		std::cout << this->getName() << " failed robotomized" << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getRights() != true) {
		throw HaveNoSign();
	} else {
		if (this->getExecGrade() >= executor.getGrade()) {
			std::cout << "Drilllllll....." << std::endl;
			this->action();
		} else {
			throw GradeTooLowException();
		}
	}
}