#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#define PATH "accounts.txt"
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

bool fileRead(string path, map<string, vector<string>>& accounts) {
	ifstream fin(path);
	if (!fin) {
		cout << "������ �������� �ʽ��ϴ�." << endl;
		ofstream fout(path);
		fout.close();
		return 0;
	}

	string buf;
	while (getline(fin, buf)) {
		vector<string> line = split(buf, " ");
		accounts[line[0]] = { line[1], line[2], line[3] }; // ���¹�ȣ = ������, �ܾ�, ��й�ȣ
	}
	fin.close();
	return 1;
}

bool filewrite(string path, map<string, vector<string>> accounts) {
	ofstream fout(path);
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

int main(void) {
	map<string, vector<string>> accounts; // Ű: ���¹�ȣ, �� : [������, �ܾ�, ��й�ȣ]
	map<string, vector<string>>::iterator it; // �ڷ� ��ȸ�� ���� ������
	fileread(PATH, accounts); // ���� ���� �ʱ�ȭ (�ҷ�����)

	int init = 0;
	string currentUser;
	while (init != -1) {
		cin >> init;
		cout << "���¹�ȣ�� �Է����ּ���. (���� : -1) >> ";
		if (accounts.find(currentUser) != accounts.end()) { // ���¹�ȣ�� accounts�� ���� ���
			cout << "[����] " << accounts[currentUser][0] << "�� ȯ���մϴ� ! " << endl;
			// �α��� ���� : �޴� ���� ����
			int select = 0; // �޴� ���� ����
			while (select != 4) {
				cout << "1. �Ա� \t 2. ��� \t 3. �۱� \t 4. ��ȸ \t 5. ���� >> "; cin >> select;
				switch (select) {
				case 1: { // �Ա��ϱ�
					int deposit;
					cout << "�Աݾ��� �Է����ּ���. >> "; cin >> deposit;
					it->second[2] = to_string(stoi(it->second[2]) + deposit); // map�� value�� string���� ����Ǿ� �־ ��ȯ �ʿ�!
					filewrite(PATH, accounts); // ���Ͽ� ����
					cout << "[����] �Ա��� �Ϸ�Ǿ����ϴ�!" << endl;
					break;
				}
				case 2: { // ����ϱ�
					string password; int withdraw;
					cout << "��ݾ��� �Է����ּ���. >> "; cin >> withdraw;
					cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> password;
					if (password == it->second[2]) { // ��й�ȣ�� �´��� Ȯ��
						if (withdraw <= stoi(it->second[1])) {
							it->second[1] = to_string(stoi(it->second[1]) - withdraw);  // ����ϱ�
							filewrite(PATH, accounts); // ���Ͽ� ����
							cout << "[����] ����� �Ϸ�Ǿ����ϴ�." << endl;
						}
						else cout << "[����] �ݾ��� �����մϴ�." << endl;
					}
					else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
					break;
				}
				case 3: { // �۱��ϱ�
					string destAccount, password; int amount;
					cout << "�۱��� ���� ������ ���¹�ȣ�� �Է����ּ���. >> "; cin >> destAccount;
					it = accounts.find(destAccount);
					if (it != accounts.end()) { // �߽߰�
						cout << "�۱ݾ��� �Է����ּ���. >> "; cin >> amount;
						if (stoi(it->second[1]) <= amount) {
							cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> password;
							if (it->second[2] == password) {
								it->second[2] = to_string(stoi(it->second[2]) + amount);
								accounts[currentUser][2] = to_string(stoi(accounts[currentUser][2]) - amount);
								cout << "[����] �۱��� �Ϸ�Ǿ����ϴ�." << endl;
							}
							else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
						}
						else cout << "[����] �ݾ��� �����մϴ�." << endl;
					}
					else cout << "[����] �ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
					break;
				}
				case 4: { // ��ȸ�ϱ�
					string password;
					cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> password;
					if (accounts[currentUser][2] == password) cout << accounts[currentUser][1];
					else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
					break;
				}
				case 5: { // �����ϱ�
					cout << "[����] " << accounts[currentUser][0] << "���� ������ �����մϴ�." << endl;
					break;
				}
				default: {
					cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
				}
			}
		}
		else cout << "[����] �ش� ���¹�ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
	} 
}