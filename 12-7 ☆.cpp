#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// �ҽ� ���ϰ� ���� ������ �̸�
	const char* srcFile = "src\\Test.jpg";
	const char* destFile = "src\\TestCopy.jpg";
	
	// �ҽ� ���� ����
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cerr << "�ҽ� ������ �� �� �����ϴ�: " << srcFile << endl;
		return 1;
	}
	
	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cerr << "���� ������ �� �� �����ϴ�: " << destFile << endl;
		fsrc.close();
		return 1;
	}

	// �ҽ� ���Ͽ��� ���� ���Ϸ� �����ϱ�
	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "�� " << destFile << "�� �����߽��ϴ�." << endl;
	fsrc.close();
	fdest.close();
}