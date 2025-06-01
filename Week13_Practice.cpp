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
		cout << "파일없음" << endl;
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
	if (!fout) { // 열기 실패 검사
		cout << "파일열기 실패" << endl;
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
	map<string, int> s; // 재고를 저장할 map 자료구조 선언
	map<string, int>::iterator it; // 자료 조회를 위한 포인터
	string prod; // 제품 선택
	int cnt; // 재고 수량
	int select = 0; // 메뉴 선택 변수

	fileread(PATH, s); // 파일에서 불러오기
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
			filewrite(PATH, s); // 파일에 저장
			break;
		case 2: // 출고처리부
			cout << "상품명 >> "; cin >> prod;
			if (s.find(prod) == s.end()) { // 만약, 데이터가 없다면
				cout << "[실패] " << prod << "(라)는 재고가 존재하지 않습니다." << endl << endl;
				break;
			}
			cout << "수량 >> "; cin >> cnt;
			if (s[prod] < cnt) // 출고할 수량이 입고된 것보다 클 때
				cout << "[실패] 출고할 수량(" << cnt << ")이 입고된 수량(" << s[prod] << ")보다 큽니다.";
			else {
				s[prod] -= cnt; // 출고 수량만큼 재고 감소
				cout << "[성공] 출고가 완료되었습니다.";
				filewrite(PATH, s); // 파일에 저장
			}
			cout << endl << endl;
			break;
		case 3: // 현황처리
			idx = 1; // 현황 출력용 인덱스
			showMap(s); // 현황 출력
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