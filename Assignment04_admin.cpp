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
		cout << "파일이 존재하지 않습니다." << endl;
		ofstream fout(PATH);
		fout.close();
		return 0;
	}

	string buf;
	while (getline(fin, buf)) {
		vector<string> line = split(buf);
		accounts[line[0]] = { line[1], line[2], line[3] }; // 계좌번호 = 예금주, 잔액, 비밀번호
	}
	fin.close();
	return 1;
}

bool filewrite(map<string, vector<string>> accounts) {
	ofstream fout(PATH);
	if (!fout) { // 열기 실패 검사
		cout << "파일열기 실패" << endl;
		return 0;
	}

	for (auto item : accounts) {
		// 계좌번호 예금주 잔액 비밀번호
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
	map<string, vector<string>> accounts; // 키: 계좌번호, 값 : [예금주, 잔액, 비밀번호]
	map<string, vector<string>>::iterator it; // 자료 조회를 위한 포인터

	fileRead(accounts); // 파일에서 불러오기

	int select = 0; // 메뉴 선택 변수
	while (select != 4) {
		cout << "1. 계좌 등록\t2. 계좌 정보 수정\t3. 현황보기\t4. 종료 : ";
		cin >> select;
		switch(select) {
			case 1: { // 계좌 등록
				string accountNumber, owner, balance, password;
				cout << "계좌번호 : "; cin >> accountNumber;
				if (accounts.find(accountNumber) != accounts.end()) { // 이미 등록된 계좌인지 확인
					cout << "이미 등록된 계좌입니다." << endl;
					continue;
				}
				cout << "예금주 : "; cin >> owner;
				cout << "잔액 : "; cin >> balance;
				cout << "비밀번호 : "; cin >> password;
				accounts[accountNumber] = { owner, balance, password };
				cout << "등록되었습니다." << endl;
				filewrite(accounts); // 파일에 저장
				break;
			}
			case 2: { // 계좌 정보 수정
				string accountNumber, owner, balance, password;
				cout << "계좌번호 : "; cin >> accountNumber;
				it = accounts.find(accountNumber);
				if (it == accounts.end()) { // 존재하지 않는 계좌인지 확인
					cout << "존재하지 않는 계좌입니다." << endl;
					continue;
				}
				cout << "예금주 : "; cin >> owner;
				cout << "잔액 : "; cin >> balance;
				cout << "비밀번호 : "; cin >> password;
				it->second = { owner, balance, password }; // 정보 수정
				cout << "변경되었습니다." << endl;
				filewrite(accounts); // 파일에 저장
				break;
			}
			case 3: { // 현황 보기
				showAccount(accounts);
				break;
			}
			case 4: { // 종료
				break;
			}
			default: {
				cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
			}
		}
	}
}