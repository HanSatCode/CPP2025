#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	// ��Ʈ�� ��ü ���� �� ���� �б�
	ifstream fin;
	fin.open("student.txt");
	if(!fin) { // ���� �б� ���� Ȯ��
		cout << "������ �� �� ����" << endl;
		return 0;
	}

	char name[10], dept[10];
	int sid;

	// ���� �б�
	fin >> name;
	fin >> sid;
	fin >> dept;

	// ���� �ؽ�Ʈ�� ȭ�鿡 ���
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;	
	
	fin.close(); // ���� �б⸦ ��ġ�� ������ �ݴ´�.
}