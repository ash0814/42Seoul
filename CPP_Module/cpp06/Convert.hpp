#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <cmath>
#include <cctype>

class Convert
{
private:
	std::string input;
	double value;
public:
	Convert();
	Convert(char *input);
	~Convert();

	char toChar();
	int toInt();
	float toFloat();
	double toDouble();

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	class NonDisplayable : public std::exception
	{
		const char* what() const throw();
	};
	class Impossible : public std::exception
	{
		const char* what() const throw();
	};
};



#endif