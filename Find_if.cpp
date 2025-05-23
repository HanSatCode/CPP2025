#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v = { 1, 2, 3, 4, 5 };
	auto it = find_if(v.begin(), v.end(), [](int x) {return x % 2 == 0; });
	if (it != v.end()) {
		cout << "Found even number : " << *it << endl;
	}
	else {
		cout << "Not Found." << endl;
	}
}