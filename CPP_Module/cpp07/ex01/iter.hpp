#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *arrPtr, int len, void (*f)(T &arr))
{
	for (int i = 0; i < len; i++) {
		f(arrPtr[i]);
	}
}

template <typename T>
void print(T &a)
{
	std::cout << a << " ";
}

// template <typename T>
// void add(T &a)
// {
// 	a += 'd';
// 	a += 'a';
// 	a += 'y';
// }

#endif
