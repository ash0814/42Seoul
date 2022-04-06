#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	MutantStack();
	MutantStack(const MutantStack &ms);
	MutantStack &operator=(const MutantStack &ms);
	~MutantStack();

	
};

MutantStack::MutantStack()
{
}

MutantStack::~MutantStack()
{
}


#endif