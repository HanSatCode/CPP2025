#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v = { 1, 2, 3, 4, 5 };
	auto it = find(v.begin(), v.end(), 3);
	if (it != v.end()) {
		cout << "Found : " << *it << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
}