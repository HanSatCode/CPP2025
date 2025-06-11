#include <iostream>
using namespace std;

template <class T>
T biggest(T list[], T size) {
	T M = list[0];
	for (int i = 1; i < size; i++) {
		if (M < list[i]) M = list[i];
	}
	return M;
}

int main(void) {
	int x[] = { 1, 10, 100, 5, 4 };
	cout << biggest(x, 5) << endl;
}