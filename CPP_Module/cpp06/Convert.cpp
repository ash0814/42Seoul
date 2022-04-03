#include "./Convert.hpp"

Convert::Convert() {}

Convert::Convert(char *input)
{	
	this->input = input;
	this->value = std::strtod(input, NULL);
}

Convert::~Convert()
{
}

char Convert::toChar()
{
	if (this->input.length() == 1) {
		if (isascii(this->value) && !isprint(this->value) && !isprint((this->input)[0]))
			throw NonDisplayable();
		if (isprint((this->input)[0]))
			return (this->input)[0];
	}
	// std::cout << this->value << " "  << this->input << std::endl;
	// if (isascii(this->value) && !isprint(this->value))
	// 	throw NonDisplayable();
	// if (isprint((this->input)[0]) && (this->input).length() == 1)
	// 	return this->input[0];
	if (this->input == "nan" || this->input == "inf"
		|| this->input == "inff" || this->input == "nanf" || !isascii(this->value))
		throw Impossible();
	return static_cast<char>(this->value);
}

int Convert::toInt()
{
	if (this->input == "nan" || this->input == "inf"
		|| this->input == "inff" || this->input == "nanf")
		throw Impossible();
	if (this->value)
		return static_cast<int>(this->value);
	else {
		if (isprint((this->input)[0]) && (this->input).length() == 1)
			return static_cast<int>(this->input[0]);
		throw Impossible();
	}
	return static_cast<int>(this->value);
}
float Convert::toFloat()
{
	if (this->value >= 0)
		return static_cast<float>(this->value);
	else{
		if (isprint((this->input)[0]) && (this->input).length() == 1)
			return static_cast<float>(this->input[0]);
		throw Impossible();
	}
	return static_cast<float>(this->value);
}
double Convert::toDouble()
{
		if (this->value)
		return static_cast<double>(this->value);
	else{
		if (isascii((this->input)[0]) && (this->input).length() == 1)
			return static_cast<double>(this->input[0]);
		throw Impossible();
	}
	return static_cast<double>(this->value);
}

void Convert::printChar()
{
	try
	{
		this->toChar();
		std::cout << "'" << this->toChar() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printInt()
{
	try
	{
		std::cout << this->toInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printFloat()
{
	try
	{
		float a = this->toFloat();
		std::cout << this->toFloat();
		if (a - this->toInt() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printDouble()
{
	try
	{
		double a = this->toDouble();
		std::cout << this->toDouble();
		if (a - this->toInt() == 0)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}


const char* Convert::NonDisplayable::what() const throw() 
{
	return ("Non Displayable");
}

const char* Convert::Impossible::what() const throw() 
{
	return ("impossible");
}