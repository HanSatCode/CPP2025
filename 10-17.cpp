#include <iostream>
using namespace std;

int main() {
	double pi = 3.14; // ���� ����

	auto calc = [pi](int r) { return pi * r * r; };

	cout << "������ " << calc(3);		// ���ٽ� ȣ��. 28.26 ���
}