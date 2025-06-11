#include <iostream>
#include <map>
using namespace std;

int main() {
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
	map<string, int> per;
	string name; int score;
	int select = 0;
	while (select != 3) {
		cout << "입력 : 1, 조회 : 2, 종료 : 3 >> ";
		cin >> select;
		switch (select) {
		case 1:
			cout << "이름과 점수 >> ";
			cin >> name >> score;
			per[name] = score;
			break;
		case 2:
			cout << "이름 >> ";
			cin >> name;
			if (per.find(name) == per.end()) cout << "존재하지 않는 이름입니다.";
			else cout << name << "의 점수는 " << per[name] << endl;
			break;
		case 3:
			cout << "프로그램을 종료합니다..." << endl;
			break;
		default:
			cout << "잘못 입력하였습니다." << endl;
		}
	}
}