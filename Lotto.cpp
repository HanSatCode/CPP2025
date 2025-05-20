/*
set�� �̿��� �ζ���÷���α׷�.

1. 6���� ���ڸ� ��÷
2. �� ���ڴ� 1~45 ������ ��
3. ��÷�� ������ �ߺ��� ����
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
	cout << "[�ζ� ��ȣ ��÷��] ";
	for (it = lotto.begin(); it != lotto.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
