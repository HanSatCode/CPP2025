#include <iostream>
using namespace std;

#include "Week5_Circle.h"

int main(void) {
	Week5_Circle donut;
	double area = donut.getArea();
	cout << "donut ������ ";
	cout << area << endl;

	Week5_Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ ";
	cout << area << endl;
}