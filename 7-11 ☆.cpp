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
	friend Power operator+(int op1, Power op2);
};

void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power operator+(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick; // private 속성을 접근하기 위해
	tmp.punch = op1 + op2.punch; // 연산자 함수를 friend로 선언해야 함
	return tmp;
}

int main(void) {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a;
	a.show();
	b.show();
}