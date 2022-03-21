#include "Brain.hpp"

#include <sstream>

Brain::Brain()
{
	std::cout << "I have soooo many IDEAs!!" << std::endl;
	this->setIdea("Default Ideas");
}

Brain::Brain(const Brain &b)
{
	*this = b;
}

Brain &Brain::operator=(const Brain &b)
{
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = b.ideas[i];
	}
	return *this;
}

void Brain::setIdea(std::string id)
{
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i;
		ideas[i] = id + " [" + ss.str() + "]";
	}
}

std::string Brain::getIdea(int n)
{
	return ideas[n];
}

Brain::~Brain()
{
	std::cout << "I have NO IDEA" << std::endl;
}
