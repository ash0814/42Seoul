#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string fname;
	bool signRights;
	const int signGrade;
	const int execGrade;

public:
	Form();
	Form(std::string, bool, int, int);
	Form(const Form& f);
	virtual ~Form();

	Form &operator=(const Form &);

	void beSigned(Bureaucrat &br);

	std::string getName() const;
	bool getRights() const;
	void setRights(bool rights);

	int getSignGrade() const;
	int getExecGrade() const;

	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual void action() const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("EXCEPTION: Grade Too High");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("EXCEPTION: Grade Too Low");
		}
	};

	class HaveNoSign : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("EXCEPTION: Have No Sign to Excute this Form");
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form &f);



#endif