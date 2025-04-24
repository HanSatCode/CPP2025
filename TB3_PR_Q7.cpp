#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelectableRandom {
public:
	SelectableRandom() {
		srand((unsigned)time(0));
	}
	int next();
	int nextInRange(int start, int end);
};

int SelectableRandom::next() {
	int n = rand();
	if (n % 2 != 0 && n - 1 >= 0) n -= 1;
	else if (n % 2 != 0) n + 1;
	return n;
}

int SelectableRandom::nextInRange(int start, int end) {
	int n = rand() % (end - start + 1);
	if (n % 2 == 0 && n - 1 >= start) n -= 1;
	else if (n % 2 == 0) n += 1;
	return start + n;
}

int main(void) {
	SelectableRandom r;
	cout << "-- 0����" << RAND_MAX << "������ ���� ¦�� ���� 10�� -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10�� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}