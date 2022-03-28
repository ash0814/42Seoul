#include "./Form.hpp"

Form::Form() : fname("noname"), signRights(false), signGrade(150), execGrade(150)
{
	std::cout << "create : Default noname Form" << std::endl;
}

Form::Form(const std::string _name, bool _rights, const int _sign, const int _exec) 
	: fname(_name), signRights(_rights), signGrade(_sign), execGrade(_exec)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	std::cout << "create Form : " << this->fname << std::endl;
}

Form::Form(const Form& f)
	: fname(f.fname), signRights(f.signRights), signGrade(f.signGrade), execGrade(f.execGrade)
{
	std::cout << "create Form : " << this->fname << std::endl;
}

Form::~Form()
{
	std::cout << "Delete Form : " << this->fname << std::endl;
}

Form &Form::operator=(const Form &f)
{
	this->signRights = f.signRights;
	return *this;
}

void Form::setRights(bool rights)
{
	this->signRights = rights;
}

void Form::beSigned(Bureaucrat &br)
{
	if (br.getGrade() <= this->getSignGrade()) {
		this->setRights(true);
	} else {
		this->setRights(false);
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

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecGrade() const
{
	return execGrade;
}

std::ostream& operator<<(std::ostream& os, const Form &f)
{
	os << "<" << f.getName() << ">, Sign Rights : " << f.getRights() << std::endl;
	return os;
}