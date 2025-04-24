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
	cout << "************** �Խ����Դϴ�. **************" << endl; ;
	for (int i = 0; i < idx; i++) {
		cout << i + 1 << ": " << b[i] << endl;
	}
	cout << endl;
}

int main(void) {
	Board::add("�߰� ���� ���� ���� ���� ���� �Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}