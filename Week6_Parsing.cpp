#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cout << "7+23+5+100+25�� ���� ���� ���ڿ��� �Է��ϼ���." << endl;
	getline(cin, s, '\n');

	int sum = 0;
	int startIndex = 0;
	while (true) {
		int findIndex = s.find('+', startIndex);
		if (findIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int count = findIndex - startIndex;
		string part = s.substr(startIndex, count);
		sum += stoi(part);
		startIndex = findIndex + 1;
		cout << part << endl;
	}
	cout << "���ڵ��� ���� " << sum << endl;
}