#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#define PATH "storage.txt"

using namespace std;
vector<string> split(string str, string delimiter)
{
	vector<string> v;
	int sidx = 0;
	while (true)
	{
		int fidx = str.find(delimiter, sidx);
		if (fidx == -1)
		{
			v.push_back(str.substr(sidx));
			break;
		}
		v.push_back(str.substr(sidx, fidx - sidx));
		sidx = fidx + delimiter.length();
	}
	return v;
}

bool fileread(string path, map<string, int>& storage)
{
	ifstream fin(path);
	if (!fin) {
		cout << "���Ͼ���" << endl;
		ofstream fout(path);
		fout.close();
		return 0;
	}

	string buf;
	while (getline(fin, buf))
	{
		vector<string> line = split(buf, " ");
		//cout << buf << endl;
		storage[line[0]] = stoi(line[1]);
	}
	fin.close();
	return 1;
}

bool filewrite(string path, map<string, int> storage)
{
	ofstream fout(path);
	if (!fout) { // ���� ���� �˻�
		cout << "���Ͽ��� ����" << endl;
		return 0;
	}

	for (auto item : storage)
	{
		fout << item.first << " " << item.second << endl;
	}
	fout.close();
}


void showMap(map<string, int>& storage)
{
	for (auto item : storage)
	{
		cout << item.first << ":" << item.second << endl;
	}
}

int main(void) {
	map<string, int> s; // ��� ������ map �ڷᱸ�� ����
	map<string, int>::iterator it; // �ڷ� ��ȸ�� ���� ������
	string prod; // ��ǰ ����
	int cnt; // ��� ����
	int select = 0; // �޴� ���� ����

	fileread(PATH, s); // ���Ͽ��� �ҷ�����
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
			filewrite(PATH, s); // ���Ͽ� ����
			break;
		case 2: // ���ó����
			cout << "��ǰ�� >> "; cin >> prod;
			if (s.find(prod) == s.end()) { // ����, �����Ͱ� ���ٸ�
				cout << "[����] " << prod << "(��)�� ��� �������� �ʽ��ϴ�." << endl << endl;
				break;
			}
			cout << "���� >> "; cin >> cnt;
			if (s[prod] < cnt) // ����� ������ �԰�� �ͺ��� Ŭ ��
				cout << "[����] ����� ����(" << cnt << ")�� �԰�� ����(" << s[prod] << ")���� Ů�ϴ�.";
			else {
				s[prod] -= cnt; // ��� ������ŭ ��� ����
				cout << "[����] ��� �Ϸ�Ǿ����ϴ�.";
				filewrite(PATH, s); // ���Ͽ� ����
			}
			cout << endl << endl;
			break;
		case 3: // ��Ȳó��
			idx = 1; // ��Ȳ ��¿� �ε���
			showMap(s); // ��Ȳ ���
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