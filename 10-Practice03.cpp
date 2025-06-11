#include <iostream>
#include <vector>
using namespace std;

template <class T>
void reverseArray(T list[], int size) {
	vector<T> tempList;
	for (int i = 0; i < size; i++) {
		tempList.push_back(list[size - 1 - i]);
	}
	for (int i = 0; i < size; i++) {
		list[i] = tempList[i];
	}
}


int main(void) {
	int x[] = { 1, 10, 100, 5 , 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
}