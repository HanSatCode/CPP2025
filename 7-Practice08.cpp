#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
	friend Circle& operator++(Circle &op1);
	friend Circle operator++(Circle &op1, int op2);
};

Circle& operator++(Circle &op1) {
	op1.radius++;
	return op1;
}

Circle operator++(Circle &op1, int op2) {
	Circle temp = op1;
	op1.radius++;
	return temp;
}

int main(void) {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}