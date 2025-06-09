/*
재고관리 프로그램.

1. 입고 2. 줄고 3. 현황 4. 종료 : (입력받기)

# 입고처리
상품명 : (string 입력받기)
수량 : (int 입력받기)

# 출고처리
상품명 : (string 입력받기)
수량 : (int 입력받기)

# 현황
신라면 : 1500
너구리 : 700
사이다 : 5000
...
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> s;
	map<string, int>::iterator it; // 자료 조회를 위한 포인터
	string prod; // 제품 선택
	int cnt; // 재고 수량
	int select = 0;
	int idx = 0;
	while (select != 4) {
		cout << "1. 입고\t2. 출고\t3. 현황\t4. 종료 >> ";
		cin >> select;
		switch (select) {
		case 1: // 입고리처리부
			cout << "상품명 >> "; cin >> prod;
			cout << "수량 >> "; cin >> cnt;
			if (s.find(prod) == s.end()) s[prod] = cnt; // 만약, 데이터가 없다면? 최초 등록
			else s[prod] += cnt; // 데이터가 있다면? 누적
			cout << "[성공] 입고가 완료되었습니다." << endl << endl;
			break;
		case 2: // 출고처리부
			cout << "상품명 >> "; cin >> prod;
			if (s.find(prod) == s.end()) { // 만약, 데이터가 없다면?
				cout << "[실패] " << prod << "(라)는 재고가 존재하지 않습니다." << endl << endl;
				break;
			}
			cout << "수량 >> "; cin >> cnt;
			if (s[prod] < cnt) // 출고할 수량이 입고된 것보다 클 때
				cout << "[실패] 출고할 수량(" << cnt << ")이 입고된 수량(" << s[prod] << ")보다 큽니다."; 
			else {
				s[prod] -= cnt;
				cout << "[성공] 출고가 완료되었습니다.";
			}
			cout << endl << endl;
			break;
		case 3: // 현황처리
			idx = 1;
			for (it = s.begin(); it != s.end(); it++) {
				cout << "[" << idx << "] " << it->first << " : " << it->second << endl; // first = key, second = value
				idx++;
			}
			cout << endl << endl;
			break;
		case 4:
			cout << "[종료]" << endl;
			break;
		default:
			cout << "[오류] 잘못입력하셨습니다. 다시 선택해주세요." << endl << endl;
		}
	}
}