#include "./Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (value << this->fractBit);
}

Fixed::Fixed(float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fvalue * (1 << 8));
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed& Fixed::operator=(const Fixed &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = fix.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fix)
{
	os << (float)(fix.getRawBits()) / (1 << fix.fractBit);
	return os;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return this->value;
}

int Fixed::toInt(void) const
{
	return this->value >> this->fractBit;
}