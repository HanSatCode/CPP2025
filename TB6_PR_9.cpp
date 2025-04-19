#include <iostream>
#include <string>
using namespace std;

class Board {
	static int idx;
	static string b[100];
public:
	static void add(string des);
	static void print();
};


int Board::idx = 0;
string Board::b[100];

void Board::add(string des) {
	b[idx] = des;
	idx++;
}

void Board::print() {
	cout << "************** 게시판입니다. **************" << endl; ;
	for (int i = 0; i < idx; i++) {
		cout << i + 1 << ": " << b[i] << endl;
	}
	cout << endl;
}

int main(void) {
	Board::add("중간 고사는 감독 없는 자율 시험 입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}