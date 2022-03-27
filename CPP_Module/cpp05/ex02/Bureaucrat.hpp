#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &b);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &);

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(int const grade);
	void decrementGrade(int const grade);

	void signForm(Form &f);

	void executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("Grade Too High");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("Grade Too Low");
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu);


#endif