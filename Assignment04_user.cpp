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
		cout << "파일이 존재하지 않습니다." << endl;
		ofstream fout(path);
		fout.close();
		return 0;
	}

	string buf;
	while (getline(fin, buf)) {
		vector<string> line = split(buf, " ");
		accounts[line[0]] = { line[1], line[2], line[3] }; // 계좌번호 = 예금주, 잔액, 비밀번호
	}
	fin.close();
	return 1;
}

bool filewrite(string path, map<string, vector<string>> accounts) {
	ofstream fout(path);
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

int main(void) {
	map<string, vector<string>> accounts; // 키: 계좌번호, 값 : [예금주, 잔액, 비밀번호]
	map<string, vector<string>>::iterator it; // 자료 조회를 위한 포인터
	fileread(PATH, accounts); // 계좌 정보 초기화 (불러오기)

	int init = 0;
	string currentUser;
	while (init != -1) {
		cin >> init;
		cout << "계좌번호를 입력해주세요. (종료 : -1) >> ";
		if (accounts.find(currentUser) != accounts.end()) { // 계좌번호가 accounts에 있을 경우
			cout << "[성공] " << accounts[currentUser][0] << "님 환영합니다 ! " << endl;
			// 로그인 성공 : 메뉴 구현 구간
			int select = 0; // 메뉴 선택 변수
			while (select != 4) {
				cout << "1. 입금 \t 2. 출금 \t 3. 송금 \t 4. 조회 \t 5. 종료 >> "; cin >> select;
				switch (select) {
				case 1: { // 입금하기
					int deposit;
					cout << "입금액을 입력해주세요. >> "; cin >> deposit;
					it->second[2] = to_string(stoi(it->second[2]) + deposit); // map의 value는 string으로 저장되어 있어서 변환 필요!
					filewrite(PATH, accounts); // 파일에 저장
					cout << "[성공] 입금이 완료되었습니다!" << endl;
					break;
				}
				case 2: { // 출금하기
					string password; int withdraw;
					cout << "출금액을 입력해주세요. >> "; cin >> withdraw;
					cout << "비밀번호를 입력해주세요. >> "; cin >> password;
					if (password == it->second[2]) { // 비밀번호가 맞는지 확인
						if (withdraw <= stoi(it->second[1])) {
							it->second[1] = to_string(stoi(it->second[1]) - withdraw);  // 출금하기
							filewrite(PATH, accounts); // 파일에 저장
							cout << "[성공] 출금이 완료되었습니다." << endl;
						}
						else cout << "[실패] 금액이 부족합니다." << endl;
					}
					else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
					break;
				}
				case 3: { // 송금하기
					string destAccount, password; int amount;
					cout << "송금을 받을 상대방의 계좌번호를 입력해주세요. >> "; cin >> destAccount;
					it = accounts.find(destAccount);
					if (it != accounts.end()) { // 발견시
						cout << "송금액을 입력해주세요. >> "; cin >> amount;
						if (stoi(it->second[1]) <= amount) {
							cout << "비밀번호를 입력해주세요. >> "; cin >> password;
							if (it->second[2] == password) {
								it->second[2] = to_string(stoi(it->second[2]) + amount);
								accounts[currentUser][2] = to_string(stoi(accounts[currentUser][2]) - amount);
								cout << "[성공] 송금이 완료되었습니다." << endl;
							}
							else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
						}
						else cout << "[실패] 금액이 부족합니다." << endl;
					}
					else cout << "[실패] 해당 계좌번호가 존재하지 않습니다." << endl;
					break;
				}
				case 4: { // 조회하기
					string password;
					cout << "비밀번호를 입력해주세요. >> "; cin >> password;
					if (accounts[currentUser][2] == password) cout << accounts[currentUser][1];
					else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
					break;
				}
				case 5: { // 종료하기
					cout << "[종료] " << accounts[currentUser][0] << "님의 세션을 종료합니다." << endl;
					break;
				}
				default: {
					cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
				}
			}
		}
		else cout << "[실패] 해당 계좌번호가 존재하지 않습니다. 다시 입력해주세요." << endl;
	} 
}