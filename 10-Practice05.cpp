#include <iostream>
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	T* tempList = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++) {
		tempList[i] = a[i];
	}
	for (int i = 0; i < sizeb; i++) {
		tempList[sizea + i] = b[i];
	}
	return tempList;
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 10 };
	int* intArr = concat(a, 5, b, 5);
	for (int i = 0; i < 10; i++) cout << intArr[i] << " ";
	cout << endl;

	double x[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double y[] = { 6.6, 7.7, 8.8, 9.9, 10.1 };
	double* doubleArr = concat(x, 5, y, 5);
	for (int i = 0; i < 10; i++) cout << doubleArr[i] << " ";
}