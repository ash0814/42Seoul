#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Convert
{
private:
	std::string input;
	double value;
public:
	Convert();
	Convert(char *input);
	~Convert();

	// char toChar();
	// int toInt();
	// float toFloat();
	// double toDouble();
};



#endif