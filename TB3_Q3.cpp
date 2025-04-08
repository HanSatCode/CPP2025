#include <iostream>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string name, int id, int balance) {
		this->name = name;
		this->id = id;
		this->balance = balance;
	}

	string getOwner() {
		return name;
	}
	
	int inquiry() {
		return balance;
	}

	void deposit(int money) {
		balance += money;
	}

	int withdraw(int money) {
		balance -= money;
		return money;
	}
};

int main(void) {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
}