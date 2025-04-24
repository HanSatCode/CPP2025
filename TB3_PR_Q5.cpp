#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
	Random() {
		srand((unsigned)time(0));
	}
	int next();
	int nextInRange(int start, int end);
};

int Random::next() {
	int n = rand();
	return n;
}

int Random::nextInRange(int start, int end) {
	int n = rand() % (end - start + 1);
	return start + n;
}

int main(void) {
	Random r;
	cout << "-- 0에서" << RAND_MAX << "까지의 랜덤 정수 10개-- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}