#include <iostream>
#include "TB3_PR_Q10_2.h"
using namespace std;

int main(void) {
	Add a;
	Sub s;
	Mul m;
	Div d;

	int x, y;
	char z;
	while (true) {
		cout << "�� ������ �����ڸ� �Է��ϼ��� >> ";
		cin >> x >> y >> z;
		switch (z) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}
}