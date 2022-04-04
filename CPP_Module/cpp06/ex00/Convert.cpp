#include "./Convert.hpp"

Convert::Convert() 
{
	this->input = "";
	this->value = 0;
	this->type = "";
}

Convert::Convert(const Convert &cvt)
{
	*this = cvt;
}

Convert &Convert::operator=(const Convert &cvt)
{
	this->input = cvt.input;
	this->value = cvt.value;
	this->type = cvt.type;
	return *this;
}

Convert::~Convert()
{
}

Convert::Convert(char *input)
{
	this->input = input;
	this->value = std::strtod(input, &check);
	if (*check == 0)
		this->type = "Number";
	else {
		if (*check == 'f' && *(check + 1) == 0)
			this->type = "Number";
		else if (isascii(*check) && !isdigit(*check) && *(check + 1) == 0 && this->value == 0)
			this->type = "Char";
		else
			this->type = "Error";
	}
}

char Convert::toChar()
{
	if (this->type == "Char") {
		if (isprint(input[0]))
			return static_cast<char>(input[0]);
		throw NonDisplayable();
	}
	else if (this->type == "Number") {
		if (isprint(static_cast<int>(this->value)))
			return static_cast<char>(this->value);
		else if (isascii(static_cast<int>(this->value)))
			throw NonDisplayable();
	}
	throw Impossible();
}

int Convert::toInt()
{
	if (this->input == "nan" || this->input == "nanf" || this->input == "+inf" || this->input == "-inf"
		|| this->input == "+inff" || this->input == "-inff" || this->input == "inf" || this->input == "inff")
		throw Impossible();
	if (this->type == "Number") {
		return static_cast<int>(this->value);
	}
	if (this->type == "Char")
		return static_cast<int>(this->input[0]);
	throw Impossible();
}
float Convert::toFloat()
{
	if (this->type == "Error")
		throw Impossible();
	if (this->type == "Char")
		return static_cast<float>(this->input[0]);
	return static_cast<float>(this->value);
}
double Convert::toDouble()
{
	if (this->type == "Error")
		throw Impossible();
	if (this->type == "Char")
		return static_cast<double>(this->input[0]);
	return static_cast<double>(this->value);
}

void Convert::printChar()
{
	try
	{
		std::cout << "char : ";
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
		std::cout << "int : " << this->toInt() << std::endl;
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
		std::cout.precision(7);
		std::cout << "float : " << this->toFloat();
		float a = this->toFloat();
		if (a - (int)a == 0)
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
		std::cout.precision(15);
		std::cout << "double : " << this->toDouble();
		double a = this->toDouble();
		if (a - (int)a == 0)
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