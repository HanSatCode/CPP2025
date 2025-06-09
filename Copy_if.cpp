#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int is_even(int i) {
	return i % 2 == 0;
}

int main() {
	vector<int> src = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> dest(src.size());

	copy_if(src.begin(), src.end(), dest.begin(), is_even);

	for (auto i : dest) {
		cout << i << " ";
	}
}