#include <iostream>
#include <map>
using namespace std;

int main() {
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << endl;
	map<string, int> per;
	string name; int score;
	int select = 0;
	while (select != 3) {
		cout << "�Է� : 1, ��ȸ : 2, ���� : 3 >> ";
		cin >> select;
		switch (select) {
		case 1:
			cout << "�̸��� ���� >> ";
			cin >> name >> score;
			per[name] = score;
			break;
		case 2:
			cout << "�̸� >> ";
			cin >> name;
			if (per.find(name) == per.end()) cout << "�������� �ʴ� �̸��Դϴ�.";
			else cout << name << "�� ������ " << per[name] << endl;
			break;
		case 3:
			cout << "���α׷��� �����մϴ�..." << endl;
			break;
		default:
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
		}
	}
}