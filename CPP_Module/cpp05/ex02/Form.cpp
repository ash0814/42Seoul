#include "./Form.hpp"

Form::Form() : fname("noname"), signRights(false), signGrade(1), execGrade(1)
{
}

Form::Form(const std::string _name, bool _rights, const int _sign, const int _exec) 
	: fname(_name), signRights(_rights), signGrade(_sign), execGrade(_exec)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& f)
	: fname(f.fname), signRights(f.signRights), signGrade(f.signGrade), execGrade(f.execGrade)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &f)
{
	this->signRights = f.signRights;
	return *this;
}

void Form::beSigned(Bureaucrat &br)
{
	if (br.getGrade() <= this->signGrade)
		this->signRights = true;
	else {
		this->signRights = false;
		throw GradeTooLowException();
	}
}

std::string Form::getName() const
{
	return fname;
}

bool Form::getRights() const
{
	return signRights;
}

std::ostream& operator<<(std::ostream& os, const Form &f)
{
	os << "<" << f.getName() << ">, Sign Rights : " << f.getRights() << std::endl;
	return os;
}