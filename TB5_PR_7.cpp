#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack() {};
	bool push(int n);
	bool pop(int& n);
};

bool MyIntStack::push(int n) {
	if (n > 9) return false;
	p[n] = n; 
	return true;
}

bool MyIntStack::pop(int &n) {
	if (n < 1) return false;
	n -= 1;
	return true;
}

int main(void) {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n = 10;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}