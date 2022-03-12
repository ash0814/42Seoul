#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(/* args */);
	~Animal();
	std::string getType();
	void makeSound();
};

//추상 클래스, 인터페이스, 다형성

#endif