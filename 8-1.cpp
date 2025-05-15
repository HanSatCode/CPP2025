#include <iostream>
#include <string>
using namespace std;

// 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
class Point {
	int x, y; // �� �� (x, y) ��ǥ��
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point { // 2���� ��鿡�� �÷����� ǥ���ϴ� Ŭ����. Point�� ��� ����
	string color; // ���� �� ǥ��
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint(); // Point�� showPoint() ȣ��
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main(void) {
	Point p; // �⺻ Ŭ������ ��ü ����
	ColorPoint cp; // �Ļ� Ŭ������ ��ü ����
	cp.set(3, 4); // �⺻ Ŭ������ ��� ȣ��
	cp.setColor("Red"); // �Ļ� Ŭ������ ��� ȣ��
	cp.showColorPoint(); // �Ļ� Ŭ������ ��� ȣ��
}