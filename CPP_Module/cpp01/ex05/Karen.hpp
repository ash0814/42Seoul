#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class Karen
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void complain(std::string level);
	Karen(/* args */);
	~Karen();
};


#endif