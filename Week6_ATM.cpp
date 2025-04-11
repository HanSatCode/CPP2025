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
			// 화면 2
			int amnt; // 금액
			string pwd; // 비밀번호
			string targetAcc; // 송금 타겟
			int targetIndex; // 송금 타겟의 인덱스

			int select = 0;
			while (select != 5) {
				cout << "1. 입금 \t 2. 출금 \t 3. 송금 \t 4. 조회 \t 5. 종료 >> ";
				cin >> select;
				
				switch (select) {
				case 1: // 입금
					cout << "입금액을 입력해주세요 >> "; cin >> amnt;
					if (acc[react].deposit(amnt)) {
						cout << "[성공] 입금이 완료되었습니다!" << endl;
					}
					else {
						cout << "[실패] 오류가 발생하였습니다." << endl;
					}
					break;
				case 2: // 출금
					cout << "출금액을 입력해주세요. >> "; cin >> amnt;
					cout << "출금을 위한 비밀번호를 입력해주세요. >> "; cin >> pwd;
					if (acc[react].withdraw(amnt, pwd)) {
						cout << "[성공] 출금이 완료되었습니다!" << endl;
					}
					else {
						cout << "[실패] 비밀번호가 틀렸습니다." << endl;
					}
					break;
				case 3: // 송금
					cout << "송금액을 입력해주세요. >> "; cin >> amnt;
					cout << "송금을 위한 비밀번호를 입력해주세요. >> "; cin >> pwd;
					cout << "송금액을 받을 계좌번호를 입력해주세요. >> "; cin >> targetAcc;

					targetIndex = FindAccIndex(acc, cnt, targetAcc);
					if (targetIndex != -1) { // 계좌번호가 있는 경우
						acc[targetIndex].deposit(amnt);
						acc[react].withdraw(amnt, pwd);
						cout << "[성공] 송금이 완료되었습니다!" << endl;
					}
					else {
						cout << "[실패] 계좌번호나 비밀번호가 틀렸습니다. 다시 시도해주세요." << endl;
					}
					break;
				case 4:
					cout << "비밀번호를 입력해주세요 >> "; cin >> pwd;
					if (acc[react].show(pwd) == 0) {
						cout << "[실패] 비밀번호가 틀렸습니다. 다시 시도해주세요." << endl;
					}
					break;
				case 5:
					cout << "[종료] " << acc[react].getName() << "님의 세션을 종료합니다." << endl;
					break;
				default:
					cout << "[오류] 잘못된 입력입니다. 다시 입력해주세요." << endl;
				}
			}
		}
		else {
			cout << "[실패] " << code << "에 해당하는 계좌가 없습니다. 다시 입력해주세요." << endl;
		}
	}

	return 0;
}