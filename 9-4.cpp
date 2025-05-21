#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	virtual void draw() { // ���� ���ε�
		Shape::draw(); // �⺻ Ŭ������ draw() ȣ��
		cout << "Circle" << endl;
	}
};

int main(void) {
	Circle circle;
	Shape* pShape = &circle;
	pShape->draw(); // ���� ���ε��� �����ϴ� ȣ��
	pShape->Shape::draw();
}