#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int select = -1;
	int sum = 0;
	while (select != 0) {
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����) >> ";
		cin >> select;

		if (select == 0) break;
		sum += select;
		v.push_back(select);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << endl << "��� : " << (double) sum / v.size() << endl;
	}
}