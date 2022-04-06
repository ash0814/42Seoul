#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
private:
	std::vector<int> data;
	unsigned int max_size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &sp);
	Span &operator=(const Span &sp);
	~Span();

	void addNumber(int num);
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end, const int &newNumber);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};


#endif