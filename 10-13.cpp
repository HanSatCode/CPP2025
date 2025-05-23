#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;
	cout << "5개의 정수를 입력하세요. >> ";
	
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
	}

	// v.begin()에서 v.end() 사이의 값을 내림차순으로 정렬
	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}