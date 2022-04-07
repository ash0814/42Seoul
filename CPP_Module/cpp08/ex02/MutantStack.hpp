#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(const MutantStack &ms) {
		*this = ms;
	}
	MutantStack &operator=(const MutantStack &ms) {
		if (this != &ms) {
			std::stack<T>::operator=(ms);
		}
		return *this;
	}
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator
		iterator;
	typedef typename std::stack<T>::container_type::const_iterator
		const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator
		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator
		const_reverse_iterator;

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	const_iterator cbegin(void) const
	{
		return (this->c.cbegin());
	}

	const_iterator cend(void) const
	{
		return (this->c.cend());
	}

	reverse_iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend(void)
	{
		return (this->c.rend());
	}

	const_reverse_iterator crbegin(void) const
	{
		return (this->c.crbegin());
	}

	const_reverse_iterator crend(void) const
	{
		return (this->c.crend());
	}
};

#endif