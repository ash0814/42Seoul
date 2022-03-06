#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int value;
	static const int fractBit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed &fix);
	Fixed &operator= (Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif