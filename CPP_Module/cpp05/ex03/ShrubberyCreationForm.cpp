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

void ShrubberyCreationForm::action() const
{
	std::string fileName = this->getName() + "_shrubbery";
	std::ofstream file(fileName);
	file << "\n\n    oxoxoo    ooxoo\n";
	file << "  ooxoxo oo  oxoxooo\n";
	file << " oooo xxoxoo ooo ooox\n";
	file << " oxo o oxoxo  xoxxoxo\n";
	file << "  oxo xooxoooo o ooo\n";
	file << "    ooo\\oo\\  /o/o\n";
	file << "        \\  \\/ /\n";
	file << "         |   /\n";
	file << "         |  |\n";
	file << "         | D|\n";
	file << "         |  |\n";
	file << "         |  |\n";
	file << "  ______/____\\____\n";
	file << "\n\n===  [" << this->getName() << "_shrubbery]\n";
	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getRights() != true) {
		throw HaveNoSign();
	} else {
		if (this->getExecGrade() >= executor.getGrade()) {
			this->action();
			std::cout << "Form <" << this->getName() << "> executing..." << std::endl;
		} else {
			throw GradeTooLowException();
		}
	}
}