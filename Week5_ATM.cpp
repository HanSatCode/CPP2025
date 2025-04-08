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
	bool transfer(Account* acc, int amnt, string pw);	// �۱��ϱ�
	bool show(string pw);								// ��ȸ�ϱ�
	
	string getName();
	string getCode();

	int getAccount(int arr[], int size, int data);

	Account(string owner, string code, int bal, string password) {
		this->owner = owner; this->code = code; this->bal = bal; this->password = password;
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

bool Account::transfer(Account* acc, int amnt, string p) {
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

string Account::getName() {
	return owner;
}

string Account::getCode() {
	return code;
}

int FindAccIndex(Account arr[], int size, string code) {
	for (int i = 0; i < size; i++) {
		if (arr[i].getCode() == code) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	Account acc[3] = {
		Account("�Ѽ���", "1234-1234", 10000, "1234"),
		Account("�̽¹�", "4321-4321", 20000, "4321"),
		Account("�ڼ���", "0000-0000", 30000, "0000"),
	};

	int cnt = 3;
	string code;

	while (true) {
		cout << "���¹�ȣ �Է� >> "; cin >> code;
		int react = FindAccIndex(acc, cnt, code);
		if (react != -1) {
			cout << "[����] " << acc[react].getName() << "��, ȯ���մϴ�!" << endl;
			break;
		}
		else {
			cout << "[����] " << code << "�� �ش��ϴ� ���°� �����ϴ�. �ٽ� �Է����ּ���." << endl;
		}
	}

	return 0;
}