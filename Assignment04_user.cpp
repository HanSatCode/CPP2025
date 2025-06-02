#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#define PATH "accounts.txt"
using namespace std;

vector<string> split(string str) // ���ڿ� �ڸ���
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

bool fileRead(map<string, vector<string>>& accounts) { // ���� �б�
	ifstream fin(PATH);
	if (!fin) { // ���� �б� ����
		cout << "[���] ������ �������� �ʽ��ϴ�." << endl;
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

bool fileWrite(map<string, vector<string>> accounts) { // ���� ����
	ofstream fout(PATH);
	if (!fout) { // ���� ���� ����
		cout << "[���] ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}

	for (auto item : accounts) {
		// ���¹�ȣ ������ �ܾ� ��й�ȣ
		fout << item.first << " " << item.second[0] << " " << item.second[1] << " " << item.second[2] << endl;
	}
	fout.close();
	return 1;
}

int main(void) {
	map<string, vector<string>> accounts; // Ű: ���¹�ȣ, �� : [������, �ܾ�, ��й�ȣ]
	map<string, vector<string>>::iterator it; // �ڷ� ��ȸ�� ���� ������
	fileRead(accounts); // ���� ���� �ʱ�ȭ (�ҷ�����)

	string currentUser;
	while (currentUser != "-1") {
		cout << "���¹�ȣ�� �Է����ּ���. (���� : -1) >> ";
		cin >> currentUser;
		if (currentUser == "-1") {
			cout << "[����] ���α׷��� �����մϴ�." << endl;
		}
		else if (accounts.find(currentUser) != accounts.end()) { // ���� ��ȣ�� accounts�� ���� ���
			it = accounts.find(currentUser);
			string accountNumber = it->first;
			string owner = it->second[0]; // ��
			string& balance = it->second[1];
			string password = it->second[2];

			cout << "[����] " << owner << "�� ȯ���մϴ� ! " << endl;
			
			// �α��� ���� : �޴� ���� ����
			int select = 0; // �޴� ���� ����
			while (select != 5) {
				cout << "1. �Ա� \t 2. ��� \t 3. �۱� \t 4. ��ȸ \t 5. ���� >> "; cin >> select;
				switch (select) {
					case 1: { // �Ա��ϱ�
						int deposit;
						cout << "�Աݾ��� �Է����ּ���. >> "; cin >> deposit;
						balance = to_string(stoi(balance) + deposit); // map�� value�� string���� ����Ǿ� �־ ��ȯ �ʿ�!
						if (fileWrite(accounts)) {
							cout << "[����] �Ա��� �Ϸ�Ǿ����ϴ�!" << endl;
						}
						else cout << "[����] ������ �߻��Ͽ����ϴ�." << endl;
						break;
					}
					case 2: { // ����ϱ�
						string checkPassword; int withdraw;
						cout << "��ݾ��� �Է����ּ���. >> "; cin >> withdraw;
						cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> checkPassword;
						if (checkPassword == password) { // ��й�ȣ�� �´��� Ȯ��
							if (withdraw <= stoi(balance)) { // ��ݾ��� �ܾ׺��� �۰ų� ���� ���
								balance = to_string(stoi(balance) - withdraw);  // ����ϱ�
								if (fileWrite(accounts)) {
									cout << "[����] ����� �Ϸ�Ǿ����ϴ�." << endl;
								}
								else cout << "[����] ������ �߻��Ͽ����ϴ�." << endl;
							}
							else cout << "[����] �ݾ��� �����մϴ�." << endl;
						}
						else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
						break;
					}
					case 3: { // �۱��ϱ�
						string destAccount, checkPassword; int amount;
						map<string, vector<string>>::iterator itDest;

						cout << "�۱��� ���� ������ ���¹�ȣ�� �Է����ּ���. >> "; cin >> destAccount;
						itDest = accounts.find(destAccount);
						if (itDest != accounts.end()) { // ���� ���°� �ִ� ���
							string &destBalance = itDest->second[1];
							cout << "�۱ݾ��� �Է����ּ���. >> "; cin >> amount;
							if (amount <= stoi(balance)) { // �۱ݾ��� ���ݾ׺��� ���� ���
								cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> checkPassword;
								if (password == checkPassword) {
									destBalance = to_string(stoi(destBalance) + amount);
									balance = to_string(stoi(balance) - amount);
									if (fileWrite(accounts)) {
										cout << "[����] �۱��� �Ϸ�Ǿ����ϴ�." << endl;
									}
									else cout << "[����] ������ �߻��Ͽ����ϴ�." << endl;
								}
								else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
							}
							else cout << "[����] �ݾ��� �����մϴ�." << endl;
						}
						else cout << "[����] �ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
						break;
					}
					case 4: { // ��ȸ�ϱ�
						string checkPassword;
						cout << "��й�ȣ�� �Է����ּ���. >> "; cin >> checkPassword;
						if (checkPassword == password) {
							cout << "[" << owner << "���� �ܾ�] " << balance << endl;
						}
						else cout << "[����] ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
						break;
					}
					case 5: { // �����ϱ�
						cout << "[����] ������ �����մϴ�." << endl;
						break;
					}
					default: {
						cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
					}
				}
			}
		}
		else cout << "[����] �ش� ���¹�ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
	} 
}