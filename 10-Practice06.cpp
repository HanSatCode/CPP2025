#include <iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* tempList = new T[sizeSrc + sizeMinus];
	int idx = 0;
	for (int i = 0; i < sizeSrc; i++) {
		bool canCopy = true;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				canCopy = false;
				break;
			}
		}
		if (canCopy) {
			tempList[idx] = src[i];
			idx++;
		}
	}
	retSize = idx;
	return tempList;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[] = { 4, 5, 6, 7 };
	int size = 0;
	int* p = remove(a, 10, b, 4, size);
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
	delete[] p;

	size = 0;
	char c[] = { 'a','b','c','d','e','f' };
	char d[] = { 'g','h','i','j','k' };
	char* q = remove(c, 6, d, 5, size);
	for (int i = 0; i < size; i++)
		cout << q[i] << ' ';
	cout << endl;
	delete[] q;
}