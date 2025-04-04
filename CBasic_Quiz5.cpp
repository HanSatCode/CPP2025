#include <iostream>
using namespace std;

int isPrime(int x);

int main(void) {
	for (int i = 2; i <= 100; i++) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
}

int isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}