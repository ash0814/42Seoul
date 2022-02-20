#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int value;
	int fractBit;
public:
	Fixed(/* args */);
	~Fixed();
	Fixed(Fixed &fix);
	Fixed &operator= (Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif