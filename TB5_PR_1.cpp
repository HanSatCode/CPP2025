#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	int x = 10;
	int y = 20;
	swap(x, y);
	cout << x << ' ' << y << endl;
}