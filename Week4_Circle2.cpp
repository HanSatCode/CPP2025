#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); // �Ű� ���� ���� ������  (�⺻/����Ʈ ������)
	Circle(int r); // �Ű� ���� �ִ� ������
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}
int main(void) {
	Circle donut; // �Ű����� ���� ������ ȣ��
	double area = donut.getArea(); // donut ��ü�� ���� �˾Ƴ���
	cout << "donut�� ������ " << area << endl;

	Circle pizza(30); // �Ű����� �ִ� ������ ȣ��
	area = pizza.getArea(); // pizza ��ü�� ���� �˾Ƴ���
	cout << "pizza�� ������ " << area << endl;

	return 0;
}