#include <iostream>
#include "Circles.h"
using namespace std;

//int Circles::numOfCircles = 0;

int main(void) {
	Circles* p = new Circles[10];
	cout << "�����ϰ� �ִ� ���� ���� = " << Circles::getNumOfCircles() << endl;

	delete[] p;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circles::getNumOfCircles() << endl;

	Circles a;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circles::getNumOfCircles() << endl;

	Circles b;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circles::getNumOfCircles() << endl;
}