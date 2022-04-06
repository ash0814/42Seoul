#include "./Array.hpp"


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
		throw std::exception();
	return arrayData[i];
}

template <typename T>
const T &Array<T>::operator[](int i) const
{
	if (i < 0 || i >= _size)
		throw std::exception();
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

