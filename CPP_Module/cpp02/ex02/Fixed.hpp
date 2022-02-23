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

	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);

	Fixed &operator=(const Fixed &fix);
	friend std::ostream& operator<<(std::ostream &os, const Fixed &fix);
};


#endif