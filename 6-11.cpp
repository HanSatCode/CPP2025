#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; }
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircle() { return numOfCircles; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;
}

int Circle::numOfCircles = 0;

int main(void) {
	Circle* p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	
	delete[] p;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	
	Circle a;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;

	Circle b;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
}