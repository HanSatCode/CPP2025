#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EvenRandom {
public:
	EvenRandom() {
		srand((unsigned)time(0));
	}
	int next();
	int nextInRange(int start, int end);
};

int EvenRandom::next() {
	int n = rand();
	if (n % 2 != 0 && n - 1 >= 0) n -= 1;
	else if (n % 2 != 0) n += 1;
	return n;
}

int EvenRandom::nextInRange(int start, int end) {
	int n = rand() % (end - start + 1);
	if (n % 2 != 0 && n - 1 >= start) n -= 1;
	else if(n % 2 != 0) n += 1;
	return start + n;
}

int main(void) {
	EvenRandom r;
	cout << "-- 0에서" << RAND_MAX << "까지의 랜덤 정수 10개-- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}