#include <iostream>
#include "Circles.h"
using namespace std;

Circles::Circles(int r) {
	radius = r;
	numOfCircles++;
}

Circles::~Circles() {
	numOfCircles--;
}

double Circles::getArea() {
	return 3.14 * radius * radius;
}

int Circles::getNumOfCircles() {
	return numOfCircles;
}