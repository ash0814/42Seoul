#include "./Convert.hpp"

Convert::Convert() {}

Convert::Convert(char *input)
{
	char *p;
	this->input = input;
	this->value = strtod(input, &p);
	std::cout << this->value << std::endl;
	std::cout << *p << std::endl;
}

Convert::~Convert()
{
}

// char Convert::toChar()
// {

// }
// int Convert::toInt()
// {

// }
// float Convert::toFloat()
// {

// }
// double Convert::toDouble()
// {

// }