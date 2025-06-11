#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int select = -1;
	int sum = 0;
	while (select != 0) {
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> select;

		if (select == 0) break;
		sum += select;
		v.push_back(select);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << endl << "평균 : " << (double) sum / v.size() << endl;
	}
}