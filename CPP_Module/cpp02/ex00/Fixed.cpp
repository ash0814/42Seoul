#include "./Fixed.hpp"
#include <iostream>

Fixed::Fixed(/* args */)
{
	this->value = 0;
	this->fractBit = 32;
	std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &fix)
{
	fix.value = this->value;
	fix.fractBit = this->fractBit;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed& operator=(Fixed &fix)
{
	this->value = fix.value;
	this->farctBit = fix.fractBit;
	return *this;
}