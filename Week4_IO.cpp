#include <iostream>
using namespace std;

int main(void) {
	cout << "�ʺ� �Է��ϼ��� >> ";

	int width;
	cin >> width; // Ű����κ��� �ʺ� �о� width ������ ����

	cout << "���̸� �Է��ϼ��� >> ";

	int height;
	cin >> height;

	int area = width * height;
	cout << "������ " << area << endl;
}