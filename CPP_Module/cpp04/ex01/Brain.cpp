#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "I have IDEA!!" << std::endl;
	this->setBrain("IDEA");
}

void Brain::setBrain(std::string id)
{
	for (int i = 0; i < 100; i++) {
		ideas[i] = id;
	}
}

Brain::~Brain()
{
	std::cout << "I have NO IDEA" << std::endl;
}