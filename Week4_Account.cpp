#include <iostream>
using namespace std;

class Account {
	// ������(string), ���¹�ȣ(string), �ܾ�(int), ��й�ȣ(string)
	// �Ա��ϱ�(�Աݾ�), ����ϱ�(��ݾ�, ��й�ȣ),
	// �۱��ϱ�(�۱ݰ���, �۱ݾ�), ��ȸ�ϱ�(��й�ȣ)
	string owner;		// ������
	string code;		// ���¹�ȣ
	int bal;			// �ܾ�
	string password;	// ��й�ȣ
public:
	bool deposit(int amnt);								// �Ա��ϱ�
	bool withdraw(int amnt, string pw);					// ����ϱ�
	bool transfer(Account * acc, int amnt, string pw);	// �۱��ϱ�
	bool show(string pw);								// ��ȸ�ϱ�

	Account(string o, string c, int b, string p) {
		owner = o; code = c; bal = b; password = p;
	}
};

bool Account::deposit(int amnt) {
	if (amnt <= 0) {
		return 0;
	}
	bal += amnt;
	return 1;
}

bool Account::withdraw(int amnt, string p) {
	if (p == password) {
		if (amnt <= 0) {
			return 0;
		}
		else if (bal < amnt) {
			return 0;
		}
		bal -= amnt;
		return 1;
	}
	else {
		return 0;
	}
}

bool Account::transfer(Account * acc, int amnt, string p) {
	bool result = withdraw(amnt, p);
	if (!result) {
		return 0;
	}
	acc->deposit(amnt);
	return 1;
}

bool Account::show(string p) {
	if (p != password) {
		return 0;
	}
	cout << owner << "���� �ܾ� : " << bal << endl;
	return 1;
}

int main(void) {
	Account acc1("��", "1234-1234", 10000, "1234");
	Account acc2("��", "5678-5678", 20000, "5678");

	acc1.transfer(&acc2, 10000, "1234");
	acc1.show("1234");
	acc2.show("5678");
}