#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *arrPtr, int len, void (*f)(T const &arr))
{
	for (int i = 0; i < len; i++) {
		f(arrPtr[i]);
	}
}

template <typename T>
void myprint(T const &a)
{
	std::cout << a << " ";
}

#endif
