#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main(void) {
	Circle donut;
	donut.radius = 1; // donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); // donut 객체의 면적 알아내기
	cout << "donut의 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30; // donut 객체의 반지름을 30으로 설정
	area = pizza.getArea(); // pizza 객체의 면적 알아내기
	cout << "pizza의 면적은 " << area << endl;
	
	return 0;
}