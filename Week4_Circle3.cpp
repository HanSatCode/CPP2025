#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); // 매개 변수 없는 생성자  (기본/디폴트 생성자)
	Circle(int r); // 매개 변수 있는 생성자
	double getArea();
};

// 위임 생성자
Circle::Circle() : Circle(1) { }

// 생성자가 하나라도 선언되어 있는 경우, 컴파일러는 기본 생성자를 만들어주지 않음
Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}
int main(void) {
	Circle donut; // 매개변수 없는 생성자 호출
	double area = donut.getArea(); // donut 객체의 면적 알아내기
	cout << "donut의 면적은 " << area << endl;

	Circle pizza(30); // 매개변수 있는 생성자 호출
	area = pizza.getArea(); // pizza 객체의 면적 알아내기
	cout << "pizza의 면적은 " << area << endl;

	return 0;
}