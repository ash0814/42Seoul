#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <typeinfo>

template <typename T>
class Array
{
private:
	T *arrayData;
	int _size;
public:
	Array();
	Array(int n);
	Array(const Array &a);
	~Array();

	Array &operator=(const Array &a);
	T &operator[](int i);
	const T &operator[](int i) const;
	int size();
	class RangeOver : public std::exception
	{
	public:
		const char* what() const throw() {
			return ("Range Over");
		}
	};
};

template <typename T>
Array<T>::Array()
{
	arrayData = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(int n)
{
	arrayData = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &a)
{
	arrayData = new T[a._size];
	*this = a;
}

template <typename T>
Array<T>::~Array()
{
	delete [] arrayData;
}

template <typename T>
T &Array<T>::operator[](int i)
{
	if (i < 0 || i >= _size)
		throw RangeOver();
	return arrayData[i];
}

template <typename T>
const T &Array<T>::operator[](int i) const
{
	if (i < 0 || i >= _size)
		throw RangeOver();
	return arrayData[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &a)
{
	this->_size = a._size;
	if (this != &a) {
		delete this->arrayData;
		this->arrayData = new T[a._size];
		for (int i = 0; i < a._size; i++) {
			this->arrayData[i] = a.arrayData[i];
		}
	}
	return *this;
}

template <typename T>
int Array<T>::size()
{
	return (_size);
}

#endif