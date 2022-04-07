#include "./Span.hpp"

Span::Span() {}

Span::Span(unsigned int N)
{
	data.reserve(N);
	max_size = N;
}

Span::Span(const Span &sp)
{
	*this = sp;
}

Span &Span::operator=(const Span &sp)
{
	this->max_size = sp.max_size;
	this->data.resize(sp.data.capacity());
	for (unsigned int i = 0; i < this->max_size; i++)
		this->data.push_back(sp.data[i]);
	return *this;
}

Span::~Span()
{
	//소멸자에서 free나 clear?
}

void Span::addNumber(int num)
{
	if (data.size() == max_size)
		throw SpanIsFull();
	this->data.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end, const int &newNumber)
{
	std::vector<int>::iterator i;
	i = start;
	while (i < end)
	{
		addNumber(newNumber);
		i++;
	}
}
unsigned int Span::shortestSpan()
{
	if (this->data.size() < 2)
		throw NeedMoreElements();
	unsigned int ret = this->data[0];
	std::vector<int> cp(this->data);
	std::sort(cp.begin(), cp.end());
	for (unsigned int i = 0; i < cp.size() - 1; i++) {
		if (cp[i+1] - cp[i] < (int)ret)
			ret = cp[i+1] - cp[i];
	}
	return (ret);
}

unsigned int Span::longestSpan()
{
	if (this->data.size() < 2)
		throw NeedMoreElements();
	unsigned int ret = 0;
	int a = *std::max_element(this->data.begin(), this->data.end());
	int b =  *std::min_element(this->data.begin(), this->data.end());
	ret = a - b;
	return (ret);
}

const char * Span::NeedMoreElements::what() const throw()
{
	return ("Span Needs More Elements");
}

const char * Span::SpanIsFull::what() const throw()
{
	return ("Span is Full");
}
