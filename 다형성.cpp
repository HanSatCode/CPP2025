#include <iostream>

class Animal {
public:
	void move() {};
};

class Person : public Animal {
public:
	void handling() {};
};

class Tiger : public Animal {
public:
	void hunt() {};
};

int main() {
	Animal* a[3];
	a[0] = new Person;
	a[1] = new Tiger;
	a[2] = new Tiger;
	
	for (int i = 0; i < 3; i++) {
		a[i]->move();
	}
}