#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "./Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _name);
	RobotomyRequestForm(const RobotomyRequestForm &scf);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &scf);

	void execute(Bureaucrat const & executor) const;
	void action() const;
};

#endif