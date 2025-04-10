#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int radius);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() :Circle(1) { }

Circle::Circle(int radius) { 
	this->radius = radius;
	cout << "积己磊 角青 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "家戈磊 角青 radius = " << radius << endl;
}

void increase(Circle& c) {
	c.setRadius(c.getRadius() + 1);
}

int main(void) {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}