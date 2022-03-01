#include "./Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(int value)
{
	this->value = (value << this->fractBit);
}

Fixed::Fixed(float fvalue)
{
	this->value = roundf(fvalue * (1 << 8));
}

Fixed::Fixed(const Fixed &fix)
{
	*this = fix;
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	this->value = fix.getRawBits();
	return *this;
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
	return ((float)this->value / (1 << 8));
}

int Fixed::toInt(void) const
{
	return this->value >> this->fractBit;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

Fixed &Fixed::operator*(const Fixed &fix)
{
	float a, b;
	a = this->toFloat();
	b = fix.toFloat();
	this->value = (a * b) * (1 << 8);
	return *this;
}

Fixed &Fixed::operator/(const Fixed &fix)
{
	float a, b;
	a = this->toFloat();
	b = fix.toFloat();
	this->value = (a / b) * (1 << 8);
	return *this;
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->toFloat());
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->toFloat());
	--(*this);
	return tmp;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << (float)(fix.getRawBits()) / (1 << 8);
	return os;
}

bool operator==(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool operator>(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool operator>=(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits());
}

bool operator<(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits());
}

bool operator<=(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits());
}

bool operator!=(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() != b.getRawBits());
}