#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFound : public std::exception
{
	public:
	const char * what() const throw() {
		return ("Target Not Found");
	}
};

template <typename T>
typename T::iterator easyfind(T &t, int i)
{
	typename T::iterator it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw NotFound();
	return it;
}

#endif