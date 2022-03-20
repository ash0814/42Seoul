#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &b);
	Brain &operator=(const Brain &b);
	void setBrain(std::string id);
	std::string getBrain(int n);
	~Brain();
};


#endif