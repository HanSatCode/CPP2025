#include <iostream>
using namespace std;

#include "Week5_Circle.h"

int main(void) {
	Week5_Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 ";
	cout << area << endl;

	Week5_Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 ";
	cout << area << endl;
}