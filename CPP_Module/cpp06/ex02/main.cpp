#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"
#include <iostream>
#include <random>
#include <ctime>

Base * generate(void)
{
	srand((unsigned int)time(NULL));
	if (rand() % 3 == 0) {
		std::cout << "Gernerate A Class" << std::endl;
		return new A();
	}
	else if (rand() % 3 == 1) {
		std::cout << "Gernerate B Class" << std::endl;
		return new B();
	}
	else {
		std::cout << "Gernerate C Class" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	std::cout << "Ptr" << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Ref" << std::endl;
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch(const std::exception& e){ }
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch(const std::exception& e){ }
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch(const std::exception& e){ }
	
}

int main()
{
	Base *bb = generate();
	
	std::cout << std::endl;
	identify(bb);
	std::cout << std::endl;
	identify(*bb);
	return (0);
}