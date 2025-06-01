#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#define PATH "accounts.txt"
using namespace std;

vector<string> split(string str)
{
	vector<string> temp;
	int startIndex = 0;
	while (true)
	{
		int findIndex = str.find(" ", startIndex);
		if (findIndex == -1)
		{
			temp.push_back(str.substr(startIndex));
			break;
		}
		temp.push_back(str.substr(startIndex, findIndex - startIndex));
		startIndex = findIndex + 1;
	}
	return temp;
}

bool fileRead(map<string, vector<string>>& accounts) {
	ifstream fin(PATH);
	if (!fin) {
		cout << "������ �������� �ʽ��ϴ�." << endl;
		ofstream fout(PATH);
		fout.close();
		return 0;
	}

	string buf;
	while (getline(fin, buf)) {
		vector<string> line = split(buf);
		accounts[line[0]] = { line[1], line[2], line[3] }; // ���¹�ȣ = ������, �ܾ�, ��й�ȣ
	}
	fin.close();
	return 1;
}

bool filewrite(map<string, vector<string>> accounts) {
	ofstream fout(PATH);
	if (!fout) { // ���� ���� �˻�
		cout << "���Ͽ��� ����" << endl;
		return 0;
	}

	for (auto item : accounts) {
		// ���¹�ȣ ������ �ܾ� ��й�ȣ
		fout << item.first << " " << item.second[0] << " " << item.second[1] << " " << item.second[2] << endl;
	}
	fout.close();
}

void showAccount(map<string, vector<string>>& accounts){
	for (auto item : accounts){
		cout << item.first << " | " << item.second[0] << " | " << item.second[1] << " | " << item.second[2] << endl;
	}
}

int main(void) {
	map<string, vector<string>> accounts; // Ű: ���¹�ȣ, �� : [������, �ܾ�, ��й�ȣ]
	map<string, vector<string>>::iterator it; // �ڷ� ��ȸ�� ���� ������

	fileRead(accounts); // ���Ͽ��� �ҷ�����

	int select = 0; // �޴� ���� ����
	while (select != 4) {
		cout << "1. ���� ���\t2. ���� ���� ����\t3. ��Ȳ����\t4. ���� : ";
		cin >> select;
		switch(select) {
			case 1: { // ���� ���
				string accountNumber, owner, balance, password;
				cout << "���¹�ȣ : "; cin >> accountNumber;
				if (accounts.find(accountNumber) != accounts.end()) { // �̹� ��ϵ� �������� Ȯ��
					cout << "�̹� ��ϵ� �����Դϴ�." << endl;
					continue;
				}
				cout << "������ : "; cin >> owner;
				cout << "�ܾ� : "; cin >> balance;
				cout << "��й�ȣ : "; cin >> password;
				accounts[accountNumber] = { owner, balance, password };
				cout << "��ϵǾ����ϴ�." << endl;
				filewrite(accounts); // ���Ͽ� ����
				break;
			}
			case 2: { // ���� ���� ����
				string accountNumber, owner, balance, password;
				cout << "���¹�ȣ : "; cin >> accountNumber;
				it = accounts.find(accountNumber);
				if (it == accounts.end()) { // �������� �ʴ� �������� Ȯ��
					cout << "�������� �ʴ� �����Դϴ�." << endl;
					continue;
				}
				cout << "������ : "; cin >> owner;
				cout << "�ܾ� : "; cin >> balance;
				cout << "��й�ȣ : "; cin >> password;
				it->second = { owner, balance, password }; // ���� ����
				cout << "����Ǿ����ϴ�." << endl;
				filewrite(accounts); // ���Ͽ� ����
				break;
			}
			case 3: { // ��Ȳ ����
				showAccount(accounts);
				break;
			}
			case 4: { // ����
				break;
			}
			default: {
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
			}
		}
	}
}