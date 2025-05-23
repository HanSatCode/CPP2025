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
	Power operator++(int x);
};

void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power Power::operator++(int x) {
	Power temp = *this; // 증가 이전 객체 상태를 저장
	this->kick++;
	this->punch++;
	return temp; // 증가 이전 객체 상태 리턴
}

int main(void) {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++; // 후위 ++ 연산자 사용
	a.show(); // a의 파워는 1 증가됨
	b.show(); // b는 a가 증가되기 이전 상태를 가짐
}