#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;
	cout << "5���� ������ �Է��ϼ���. >> ";
	
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n); // Ű���忡�� ���� ������ ���Ϳ� ����
	}

	// v.begin()���� v.end() ������ ���� ������������ ����
	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}