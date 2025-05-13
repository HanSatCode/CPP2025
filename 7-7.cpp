#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+(int op2); // + 연산자 함수 선언
};

void Power::show() {
	cout << "kick = " << kick << ", ";
	cout << "punch = " << punch << endl;
}

Power Power::operator+(int op2) {
	Power temp; // 임시 객체 생성
	temp.kick = this->kick + op2; // kick에 op2 더하기
	temp.punch = this->punch + op2; // punch에 op2 더하기
	return temp; // 임시 객체 리턴
}

int main(void) {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2; // Power 객체와 정수 더하기
	a.show();
	b.show();
}