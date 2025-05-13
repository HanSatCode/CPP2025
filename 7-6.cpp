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
	Power& operator+=(Power op2); // += ������ �Լ� ����
};

void Power::show() {
	cout << "kick = " << kick << ", ";
	cout << "punch = " << punch << endl;
}

Power& Power::operator+=(Power op2) {
	this->kick = this->kick + op2.kick; // kick ���ϱ�
	this->punch = this->punch + op2.punch; // punch ���ϱ�
	return *this; // ���� ��� ����
}

int main(void) {
	Power a(3, 5), b(4, 6), c;
	a.show();
	b.show();
	c = a += b; // Power ��ü ���ϱ�
	a.show();
	c.show();
}