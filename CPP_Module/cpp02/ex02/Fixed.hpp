#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractBit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(int value);
	Fixed(float fvalue);
	Fixed(const Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	Fixed &operator=(const Fixed &fix);
	Fixed &operator*(const Fixed &fix);
	Fixed &operator/(const Fixed &fix);
	Fixed &operator++();
	const Fixed operator++(int);
	Fixed &operator--();
	const Fixed operator--(int);

};

std::ostream& operator<<(std::ostream &os, const Fixed &fix);
bool operator==(const Fixed &a, const Fixed &b);
bool operator>(const Fixed &a, const Fixed &b);
bool operator>=(const Fixed &a, const Fixed &b);
bool operator<(const Fixed &a, const Fixed &b);
bool operator<=(const Fixed &a, const Fixed &b);
bool operator!=(const Fixed &a, const Fixed &b);


#endif