#include <iostream>
#include <string>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* r = new int[size*2];
	for (int i = 0; i < size; i++) {
		r[i] = s1[i];
	}
	for (int j = size; j < size * 2; j++) {
		r[j] = s2[j - size];
	}
	return r;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* r = new int[size];
	for (int i = 0; i < size; i++) {
		bool TF = false;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) TF = true;
		}
		if (!TF) {
			r[retSize] = s1[i];
			retSize++;
		}
	}
	if (retSize == 0) return NULL;
	else return r;
}

int main(void) {
	
	int a1[5], a2[5];
	cout << "���� 5�� �Է��϶�. �迭 x�� �����Ѵ� >> ";
	cin >> a1[0] >> a1[1] >> a1[2] >> a1[3] >> a1[4];

	cout << "���� 5�� �Է��϶�. �迭 y�� �����Ѵ� >> ";
	cin >> a2[0] >> a2[1] >> a2[2] >> a2[3] >> a2[4];

	int* c = ArrayUtility2::concat(a1, a2, 5);
	cout << "��ģ ���� �迭�� ����Ѵ�." << endl;
	for (int i = 0; i < 5 * 2; i++) {
		cout << c[i] << ' ';
	}
	cout << endl;

	int ret = 0;
	int* r = ArrayUtility2::remove(a1, a2, 5, ret);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << ret << endl;
	for (int i = 0; i < ret; i++) {
		cout << r[i] << ' ';
	}
	delete[] c;
	delete[] r;
	cout << endl;

}