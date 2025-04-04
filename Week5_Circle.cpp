#include <iostream>
using namespace std;

#include "Week5_Circle.h"

Week5_Circle::Week5_Circle() : Week5_Circle(1) { }

Week5_Circle::Week5_Circle(int r) {
	radius = r;
	cout << "반지름 " << radius;
	cout << " 원 생성" << endl;
}

double Week5_Circle::getArea() {
	return 3.14 * radius * radius;
}