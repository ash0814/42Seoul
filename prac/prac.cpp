#include <iostream>

class Animal {
	private :
	int food;
	int weight;

	public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
};