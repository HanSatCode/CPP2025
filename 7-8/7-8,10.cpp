#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator++ ();
	Power operator++ (int x);
};

void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power& Power::operator++() {
	kick++;
	punch++;
	return *this;
}

Power Power::operator++(int x) {
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;
}

int main(void) {
	Power a(3, 5), b, c;
	a.show();
	b.show();
	c.show();
	b = ++a;
	c = a++;
	a.show();
	b.show();
	c.show();
}