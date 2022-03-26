#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150)
{
	std::cout << "<" << name << ">, grade <" << grade << "> create" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
		std::cout << "<" << name << ">, grade <" << grade << "> create" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade)
{
	std::cout << "<" << name << ">, grade <" << grade << "> create" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "<" << name << ">, grade <" << grade << "> remove" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	this->grade = b.getGrade();
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return name;
}

int  Bureaucrat::getGrade(void) const
{
	return grade;
}

void  Bureaucrat::incrementGrade(int const grade)
{
	if (this->grade - grade < 1) {
		throw GradeTooHighException();
	}
	this->grade -= grade;
}

void  Bureaucrat::decrementGrade(int const grade)
{
	if (this->grade + grade > 150) {
		throw GradeTooLowException();
	}
	this->grade += grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">";
	return os;
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getRights() == true) {
		std::cout << this->name << " signed " << f.getName() << std::endl;
	} else {
		std::cout << this->name << " couldn't sign " 
		<< f.getName() << " because "<< this->name << 
		" has too low grade to sign this form." << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	// <bureaucrat> executed <form>
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}