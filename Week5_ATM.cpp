#include <iostream>
using namespace std;

class Account {
	// 예금주(string), 계좌번호(string), 잔액(int), 비밀번호(string)
	// 입금하기(입금액), 출금하기(출금액, 비밀번호),
	// 송금하기(송금계좌, 송금액), 조회하기(비밀번호)
	string owner;		// 예금주
	string code;		// 계좌번호
	int bal;			// 잔액
	string password;	// 비밀번호
public:
	bool deposit(int amnt);								// 입금하기
	bool withdraw(int amnt, string pw);					// 출금하기
	bool transfer(Account* acc, int amnt, string pw);	// 송금하기
	bool show(string pw);								// 조회하기
	
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
	cout << owner << "님의 잔액 : " << bal << endl;
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
		Account("한석희", "1234-1234", 10000, "1234"),
		Account("이승민", "4321-4321", 20000, "4321"),
		Account("박성종", "0000-0000", 30000, "0000"),
	};

	int cnt = 3;
	string code;

	while (true) {
		cout << "계좌번호 입력 >> "; cin >> code;
		int react = FindAccIndex(acc, cnt, code);
		if (react != -1) {
			cout << "[성공] " << acc[react].getName() << "님, 환영합니다!" << endl;
			break;
		}
		else {
			cout << "[실패] " << code << "에 해당하는 계좌가 없습니다. 다시 입력해주세요." << endl;
		}
	}

	return 0;
}