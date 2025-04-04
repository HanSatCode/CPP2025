#include <iostream>
using namespace std;

class Rectangle {
	int width;
	int height;
public:
	Rectangle();
	Rectangle(int a);
	Rectangle(int w, int h);
	int getArea();
};

// 생성자가 선언되어 있지 않으면, 기본 생성자를 자동으로 생성함
Rectangle::Rectangle() {
	width = 1, height = 1;
}

Rectangle::Rectangle(int a) {
	width = a, height = a;
}

Rectangle::Rectangle(int w, int h) {
	width = w, height = h;
}

int Rectangle::getArea() {
	return width * height;
}

int main(void) {
	Rectangle A;
	Rectangle B(3);
	Rectangle C(3, 5);
	cout << "A의 넓이 : " << A.getArea() << endl;
	cout << "B의 넓이 : " << B.getArea() << endl;
	cout << "C의 넓이 : " << C.getArea() << endl;
}