#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_even(int i) {
	return i % 2 == 0;
}

int main(void) {
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int count = count_if(v.begin(), v.end(), is_even);
	cout << "Number of even numbers: " << count << endl;
}