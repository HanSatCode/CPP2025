#include <iostream>
using namespace std;

int add(int num1[], int size, int num2[] = {}) {
	int s = 0;
	for (int i = 0; i < size; i++) {
		s += num1[i];
	}
	if (num2) {
		for (int i = 0; i < size; i++) {
			s += num2[i];
		}
	}
	return s;
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9 , 10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}