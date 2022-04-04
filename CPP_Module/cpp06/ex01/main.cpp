#include "Data.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	struct Data *d = new Data();

	d->c = 'S';
	d->i = 814;
	uintptr_t uptr = serialize(d);
	struct Data *newData = deserialize(uptr);
	std::cout << d << std::endl;
	std::cout << uptr << std::endl;
	std::cout << newData << std::endl;
	std::cout << newData->c << std::endl;
	std::cout << newData->i << std::endl;

	return (0);
}