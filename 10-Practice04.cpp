#include <iostream>
using namespace std;

template <class T>
bool search(T e, T list[], int size) {
	for (int i = 0; i < size; i++) {
		if (list[i] == e) return true;
	}
	return false;
}

int main(void) {
	int x[] = { 1, 10, 100, 5 , 4 };
	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ִ�";
	else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�";
}