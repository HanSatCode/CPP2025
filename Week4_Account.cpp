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
	bool transfer(Account * acc, int amnt, string pw);	// 송금하기
	bool show(string pw);								// 조회하기

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
	cout << owner << "님의 잔액 : " << bal << endl;
	return 1;
}

int main(void) {
	Account acc1("한", "1234-1234", 10000, "1234");
	Account acc2("이", "5678-5678", 20000, "5678");

	acc1.transfer(&acc2, 10000, "1234");
	acc1.show("1234");
	acc2.show("5678");
}