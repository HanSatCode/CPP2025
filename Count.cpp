#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v = { 1, 2, 3, 2, 1, 2, 3, 2, 1 };
	int count = std::count(v.begin(), v.end(), 2);
	std::cout << "Number of 2s: " << count << endl;
}