#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_even(int i) {
	return i % 2 == 0;
}

int main(void) {
	vector<int> v = { 1, 2, 3, 4, 5 };
	auto it = find_if(v.begin(), v.end(), is_even);
	if (it != v.end()) {
		cout << "Found even number : " << *it << endl;
	}
	else {
		cout << "Not Found." << endl;
	}
}