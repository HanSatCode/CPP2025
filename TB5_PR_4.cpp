#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) return true;
	else {
		big = (a > b) ? a : b;
		return false;
	}
}

int main(void) {
	int x = 10, y = 20;
	int result;
	if (!bigger(x, y, result)) {
		cout << result;
	}
	else {
		cout << "오류 발생";
	}
}