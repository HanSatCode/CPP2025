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
			// ȭ�� 2
			int amnt; // �ݾ�
			string pwd; // ��й�ȣ
			string targetAcc; // �۱� Ÿ��
			int targetIndex; // �۱� Ÿ���� �ε���

			int select = 0;
			while (select != 5) {
				cout << "1. �Ա� \t 2. ��� \t 3. �۱� \t 4. ��ȸ \t 5. ���� >> ";
				cin >> select;
				
				switch (select) {
				case 1: // �Ա�
					cout << "�Աݾ��� �Է����ּ��� >> "; cin >> amnt;
					if (acc[react].deposit(amnt)) {
						cout << "[����] �Ա��� �Ϸ�Ǿ����ϴ�!" << endl;
					}
					else {
						cout << "[����] ������ �߻��Ͽ����ϴ�." << endl;
					}
					break;
				case 2: // ���
					cout << "��ݾ��� �Է����ּ���. >> "; cin >> amnt;
					cout << "����� ���� ��й�ȣ�� �Է����ּ���. >> "; cin >> pwd;
					if (acc[react].withdraw(amnt, pwd)) {
						cout << "[����] ����� �Ϸ�Ǿ����ϴ�!" << endl;
					}
					else {
						cout << "[����] ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
					}
					break;
				case 3: // �۱�
					cout << "�۱ݾ��� �Է����ּ���. >> "; cin >> amnt;
					cout << "�۱��� ���� ��й�ȣ�� �Է����ּ���. >> "; cin >> pwd;
					cout << "�۱ݾ��� ���� ���¹�ȣ�� �Է����ּ���. >> "; cin >> targetAcc;

					targetIndex = FindAccIndex(acc, cnt, targetAcc);
					if (targetIndex != -1) { // ���¹�ȣ�� �ִ� ���
						acc[targetIndex].deposit(amnt);
						acc[react].withdraw(amnt, pwd);
						cout << "[����] �۱��� �Ϸ�Ǿ����ϴ�!" << endl;
					}
					else {
						cout << "[����] ���¹�ȣ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �õ����ּ���." << endl;
					}
					break;
				case 4:
					cout << "��й�ȣ�� �Է����ּ��� >> "; cin >> pwd;
					if (acc[react].show(pwd) == 0) {
						cout << "[����] ��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �õ����ּ���." << endl;
					}
					break;
				case 5:
					cout << "[����] " << acc[react].getName() << "���� ������ �����մϴ�." << endl;
					break;
				default:
					cout << "[����] �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}
		}
		else {
			cout << "[����] " << code << "�� �ش��ϴ� ���°� �����ϴ�. �ٽ� �Է����ּ���." << endl;
		}
	}

	return 0;
}