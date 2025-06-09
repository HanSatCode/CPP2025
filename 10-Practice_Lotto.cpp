/*
set을 이용한 로또추첨프로그램.

1. 6개의 숫자를 추첨
2. 각 숫자는 1~45 사이의 수
3. 추첨된 수에는 중복이 없음
*/
#include <iostream>
#include <set>
#include <random>
using namespace std;

int main(void) {
	set<int> lotto;
	set<int>::iterator it;
	srand(time(0));
	while (lotto.size() != 6) {
		lotto.insert(rand() % 45 + 1);
	}
	cout << "[로또 번호 추첨기] ";
	for (it = lotto.begin(); it != lotto.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
