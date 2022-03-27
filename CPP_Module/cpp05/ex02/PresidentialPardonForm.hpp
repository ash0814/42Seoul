#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "./Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _name);
	PresidentialPardonForm(const PresidentialPardonForm &scf);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &scf);

	void execute(Bureaucrat const & executor) const;
	void action() const;
};

#endif