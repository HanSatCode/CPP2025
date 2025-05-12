#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator+(Power op2);
	Power operator-(Power op2);
};

void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power Power::operator+(Power op2) { // + 연산자 멤버 함수 구현
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

Power Power::operator-(Power op2) { // + 연산자 멤버 함수 구현
	Power tmp;
	tmp.kick = this->kick - op2.kick;
	tmp.punch = this->punch - op2.punch;
	return tmp;
}

int main(void) {
	Power a(3, 5), b(4, 6), c, d;
	c = a + b; // 객체 a의 operator+() 멤버 함수 호출
	d = b - a; // 객체 b의 operator-() 멤버 함수 호출
	a.show();
	b.show();
	c.show();
	d.show();
}