#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> src = { 1,2,3,4,5 };
	vector<int> dest(src.size());

	move(src.begin(), src.end(), dest.begin());
	
	for (auto i : dest) {
		cout << i << ' ';
	}
}