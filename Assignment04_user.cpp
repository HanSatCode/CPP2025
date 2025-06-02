#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#define PATH "accounts.txt"
using namespace std;

vector<string> split(string str) // 문자열 자르기
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

bool fileRead(map<string, vector<string>>& accounts) { // 파일 읽기
	ifstream fin(PATH);
	if (!fin) { // 파일 읽기 실패
		cout << "[경고] 파일이 존재하지 않습니다." << endl;
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

bool fileWrite(map<string, vector<string>> accounts) { // 파일 쓰기
	ofstream fout(PATH);
	if (!fout) { // 파일 열기 실패
		cout << "[경고] 파일이 존재하지 않습니다." << endl;
		return 0;
	}

	for (auto item : accounts) {
		// 계좌번호 예금주 잔액 비밀번호
		fout << item.first << " " << item.second[0] << " " << item.second[1] << " " << item.second[2] << endl;
	}
	fout.close();
	return 1;
}

int main(void) {
	map<string, vector<string>> accounts; // 키: 계좌번호, 값 : [예금주, 잔액, 비밀번호]
	map<string, vector<string>>::iterator it; // 자료 조회를 위한 포인터
	fileRead(accounts); // 계좌 정보 초기화 (불러오기)

	string currentUser;
	while (currentUser != "-1") {
		cout << "계좌번호를 입력해주세요. (종료 : -1) >> ";
		cin >> currentUser;
		if (currentUser == "-1") {
			cout << "[종료] 프로그램을 종료합니다." << endl;
		}
		else if (accounts.find(currentUser) != accounts.end()) { // 계좌 번호가 accounts에 있을 경우
			it = accounts.find(currentUser);
			string accountNumber = it->first;
			string owner = it->second[0]; // 값
			string& balance = it->second[1];
			string password = it->second[2];

			cout << "[성공] " << owner << "님 환영합니다 ! " << endl;
			
			// 로그인 성공 : 메뉴 구현 구간
			int select = 0; // 메뉴 선택 변수
			while (select != 5) {
				cout << "1. 입금 \t 2. 출금 \t 3. 송금 \t 4. 조회 \t 5. 종료 >> "; cin >> select;
				switch (select) {
					case 1: { // 입금하기
						int deposit;
						cout << "입금액을 입력해주세요. >> "; cin >> deposit;
						balance = to_string(stoi(balance) + deposit); // map의 value는 string으로 저장되어 있어서 변환 필요!
						if (fileWrite(accounts)) {
							cout << "[성공] 입금이 완료되었습니다!" << endl;
						}
						else cout << "[실패] 문제가 발생하였습니다." << endl;
						break;
					}
					case 2: { // 출금하기
						string checkPassword; int withdraw;
						cout << "출금액을 입력해주세요. >> "; cin >> withdraw;
						cout << "비밀번호를 입력해주세요. >> "; cin >> checkPassword;
						if (checkPassword == password) { // 비밀번호가 맞는지 확인
							if (withdraw <= stoi(balance)) { // 출금액이 잔액보다 작거나 같은 경우
								balance = to_string(stoi(balance) - withdraw);  // 출금하기
								if (fileWrite(accounts)) {
									cout << "[성공] 출금이 완료되었습니다." << endl;
								}
								else cout << "[실패] 문제가 발생하였습니다." << endl;
							}
							else cout << "[실패] 금액이 부족합니다." << endl;
						}
						else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
						break;
					}
					case 3: { // 송금하기
						string destAccount, checkPassword; int amount;
						map<string, vector<string>>::iterator itDest;

						cout << "송금을 받을 상대방의 계좌번호를 입력해주세요. >> "; cin >> destAccount;
						itDest = accounts.find(destAccount);
						if (itDest != accounts.end()) { // 상대방 계좌가 있는 경우
							string &destBalance = itDest->second[1];
							cout << "송금액을 입력해주세요. >> "; cin >> amount;
							if (amount <= stoi(balance)) { // 송금액이 원금액보다 작은 경우
								cout << "비밀번호를 입력해주세요. >> "; cin >> checkPassword;
								if (password == checkPassword) {
									destBalance = to_string(stoi(destBalance) + amount);
									balance = to_string(stoi(balance) - amount);
									if (fileWrite(accounts)) {
										cout << "[성공] 송금이 완료되었습니다." << endl;
									}
									else cout << "[실패] 문제가 발생하였습니다." << endl;
								}
								else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
							}
							else cout << "[실패] 금액이 부족합니다." << endl;
						}
						else cout << "[실패] 해당 계좌번호가 존재하지 않습니다." << endl;
						break;
					}
					case 4: { // 조회하기
						string checkPassword;
						cout << "비밀번호를 입력해주세요. >> "; cin >> checkPassword;
						if (checkPassword == password) {
							cout << "[" << owner << "님의 잔액] " << balance << endl;
						}
						else cout << "[실패] 비밀번호가 일치하지 않습니다." << endl;
						break;
					}
					case 5: { // 종료하기
						cout << "[종료] 세션을 종료합니다." << endl;
						break;
					}
					default: {
						cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
					}
				}
			}
		}
		else cout << "[실패] 해당 계좌번호가 존재하지 않습니다. 다시 입력해주세요." << endl;
	} 
}