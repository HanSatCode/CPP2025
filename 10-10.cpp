#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	vector<string> sv; // ���ڿ� ���� ����
	string name;

	cout << "�̸��� 5�� �Է��϶�" << endl; // �� �ٿ� �� ���� 5���� �̸��� �Է¹���
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << " >> ";
		getline(cin, name);
		sv.push_back(name);
	}
	name = sv.at(0); // ������ ù ����
	for (int i = 0; i < sv.size(); i++) {
		if (name < sv[i]) // sv[i]�� ���ڿ��� name���� �������� �ڿ� ����
			name = sv[i]; // name�� sv[i]�� ���ڿ��� ����
	}
	cout << "�������� ���� �ڿ� ������ �̸��� " << name << endl;
}