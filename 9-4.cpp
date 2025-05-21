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
	virtual void draw() { // 동적 바인딩
		Shape::draw(); // 기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};

int main(void) {
	Circle circle;
	Shape* pShape = &circle;
	pShape->draw(); // 동적 바인딩을 포함하는 호출
	pShape->Shape::draw();
}