#include <iostream>
#include <string>
using namespace std;

class Integer {
	int n;
public:
	Integer(int n) { this->n = n; }
	Integer(string n) { this->n = stoi(n); }
	void set(int n) { this->n = n; }
	int get() { return n; }
	int isEven() { return n % 2 == 0 ? 1 : 0; }
};

int main(void) {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
}
