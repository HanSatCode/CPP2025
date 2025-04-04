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

// �����ڰ� ����Ǿ� ���� ������, �⺻ �����ڸ� �ڵ����� ������
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
	cout << "A�� ���� : " << A.getArea() << endl;
	cout << "B�� ���� : " << B.getArea() << endl;
	cout << "C�� ���� : " << C.getArea() << endl;
}