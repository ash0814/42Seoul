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

	template <typename T>
	void addAnyArray(T *arrPtr, int len)
	{
		for (int i = 0; i < len; i++) {
			addNumber(arrPtr[i]);
		}
	}

	template <typename T>
	void addAnyArray(T &t, int len)
	{
		int i = 0;
		typename T::iterator it = t.begin();
		while (it == t.end() || ++i <= len){
			addNumber(*it);
		}
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NeedMoreElements : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class SpanIsFull : public std::exception
	{
	public:
		const char *what() const throw();
	};
};


#endif