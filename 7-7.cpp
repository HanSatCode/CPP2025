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
	Power operator+(int op2); // + ������ �Լ� ����
};

void Power::show() {
	cout << "kick = " << kick << ", ";
	cout << "punch = " << punch << endl;
}

Power Power::operator+(int op2) {
	Power temp; // �ӽ� ��ü ����
	temp.kick = this->kick + op2; // kick�� op2 ���ϱ�
	temp.punch = this->punch + op2; // punch�� op2 ���ϱ�
	return temp; // �ӽ� ��ü ����
}

int main(void) {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2; // Power ��ü�� ���� ���ϱ�
	a.show();
	b.show();
}