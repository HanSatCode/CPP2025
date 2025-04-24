#include <iostream>
#include "Circles.h"
using namespace std;

//int Circles::numOfCircles = 0;

int main(void) {
	Circles* p = new Circles[10];
	cout << "생존하고 있는 원의 갯수 = " << Circles::getNumOfCircles() << endl;

	delete[] p;
	cout << "생존하고 있는 원의 갯수 = " << Circles::getNumOfCircles() << endl;

	Circles a;
	cout << "생존하고 있는 원의 갯수 = " << Circles::getNumOfCircles() << endl;

	Circles b;
	cout << "생존하고 있는 원의 갯수 = " << Circles::getNumOfCircles() << endl;
}