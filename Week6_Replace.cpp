#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cout << "���� ���� ���ڿ��� �Է��ϼ���. �Է��� ���� & �����Դϴ�." << endl;
	getline(cin, s, '&');
	cin.ignore();

	string f, r;
	cout << endl << "find : ";
	getline(cin, f, '\n');
	cout << "replace : ";
	getline(cin, r, '\n');
	
	int startIndex = 0;
	while (true) {
		int findIndex = s.find(f, startIndex);
		if (findIndex == -1) break;
		s.replace(findIndex, f.length(), r);
		startIndex = findIndex + 1;
	}

	cout << s << endl;
}