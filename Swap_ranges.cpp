#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 4, 5, 6 };

	swap_ranges(v1.begin(), v1.end(), v2.begin());

	for (int i : v1) {
		cout << i << ' ';
	}

	cout << endl;

	for (int i : v2) {
		cout << i << ' ';
	}
}