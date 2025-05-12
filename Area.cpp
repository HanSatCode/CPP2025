#include <iostream>
using namespace std;

class Shape {
public:
	virtual double area() { return 0; }
};

class Circle : public Shape {
	int r;
public:
	Circle(int r) { this->r = r; }
	virtual double area() { return 3.14 * r * r; };
};

class Rect : public Shape {
	int w, h;
public:
	Rect(int w, int h) { this->w = w; this->h = h; }
	virtual double area() { return w * h; }
};

class Triangle : public Shape {
	int w, h;
public:
	Triangle(int w, int h) { this->w = w; this->h = h; }
	virtual double area() { return w * h / 2; }
};

int main(void) {
	Shape* p[] = { new Circle(10), new Rect(5, 5), new Triangle(10, 7) };
	for (int i = 0; i < 3; i++) {
		cout << p[i]->area() << endl;
	}
}