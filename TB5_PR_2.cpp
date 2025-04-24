#include <iostream>
using namespace std;

void half(double& a) {
	a /= 2;
}

int main(void) {
	double n = 20;
	half(n);
	cout << n;
}