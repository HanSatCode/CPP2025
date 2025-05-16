#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { }
	Circle(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main(void) {
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	double c = 12.5, d = 0.3;
	myswap(c, d);
	cout << "c = " << c << ", d = " << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut 반지름 = " << donut.getRadius() << ", ";
	cout << "pizza 반지름 = " << pizza.getRadius() << endl;

}