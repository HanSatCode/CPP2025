/*
������ ���α׷�.

1. �԰� 2. �ٰ� 3. ��Ȳ 4. ���� : (�Է¹ޱ�)

# �԰�ó��
��ǰ�� : (string �Է¹ޱ�)
���� : (int �Է¹ޱ�)

# ���ó��
��ǰ�� : (string �Է¹ޱ�)
���� : (int �Է¹ޱ�)

# ��Ȳ
�Ŷ�� : 1500
�ʱ��� : 700
���̴� : 5000
...
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> s;
	map<string, int>::iterator it; // �ڷ� ��ȸ�� ���� ������
	string prod; // ��ǰ ����
	int cnt; // ��� ����
	int select = 0;
	int idx = 0;
	while (select != 4) {
		cout << "1. �԰�\t2. ���\t3. ��Ȳ\t4. ���� >> ";
		cin >> select;
		switch (select) {
		case 1: // �԰�ó����
			cout << "��ǰ�� >> "; cin >> prod;
			cout << "���� >> "; cin >> cnt;
			if (s.find(prod) == s.end()) s[prod] = cnt; // ����, �����Ͱ� ���ٸ�? ���� ���
			else s[prod] += cnt; // �����Ͱ� �ִٸ�? ����
			cout << "[����] �԰� �Ϸ�Ǿ����ϴ�." << endl << endl;
			break;
		case 2: // ���ó����
			cout << "��ǰ�� >> "; cin >> prod;
			if (s.find(prod) == s.end()) { // ����, �����Ͱ� ���ٸ�?
				cout << "[����] " << prod << "(��)�� ��� �������� �ʽ��ϴ�." << endl << endl;
				break;
			}
			cout << "���� >> "; cin >> cnt;
			if (s[prod] < cnt) // ����� ������ �԰�� �ͺ��� Ŭ ��
				cout << "[����] ����� ����(" << cnt << ")�� �԰�� ����(" << s[prod] << ")���� Ů�ϴ�."; 
			else {
				s[prod] -= cnt;
				cout << "[����] ��� �Ϸ�Ǿ����ϴ�.";
			}
			cout << endl << endl;
			break;
		case 3: // ��Ȳó��
			idx = 1;
			for (it = s.begin(); it != s.end(); it++) {
				cout << "[" << idx << "] " << it->first << " : " << it->second << endl; // first = key, second = value
				idx++;
			}
			cout << endl << endl;
			break;
		case 4:
			cout << "[����]" << endl;
			break;
		default:
			cout << "[����] �߸��Է��ϼ̽��ϴ�. �ٽ� �������ּ���." << endl << endl;
		}
	}
}