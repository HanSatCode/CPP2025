#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NameCircle : public Circle {
	string name;
public:
	NameCircle() {};
	NameCircle(int radius, string name) : Circle(radius) {
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	string getName() {
		return name;
	}
};

int main(void) {
	NameCircle pizza[5];
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	int radius;
	string name;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << " >> ";
		cin >> radius >> name;
		pizza[i] = NameCircle(radius, name);
	}
	int max = 0;
	for (int i = 1; i < 5; i++) {
		if (pizza[max].getRadius() < pizza[i].getRadius()) { max = i; }
	}
	cout << "가장 면적이 큰 피자는 " << pizza[max].getName() << endl;
}