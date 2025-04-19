#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	return min + rand() % (max - min);
}

char Random::nextAlphabet() {
	return nextInt(65, 90);
}

double Random::nextDouble() {
	return nextInt() * 0.000001;
}

int main(void) {
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(0, 100) << " ";
	}
	cout << endl;
	cout << " 알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << " ";
	}
	cout << endl;
	cout << "랜덤한 실수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << " ";
	}
	cout << endl;
}