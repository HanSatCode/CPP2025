#include <iostream>
using namespace std;

class Trace {
	static int idx;
	static string debug[100][2];
public:
	static void put(string tag, string info);
	static void print(string tag);
	static void print();
};

int Trace::idx = 0;
string Trace::debug[100][2];

void Trace::put(string tag, string info) {
	debug[idx][0] = tag;
	debug[idx][1] = info;
	idx++;
}

void Trace::print(string tag) {
	cout << "----- " << tag << "�±��� Trace ������ ����մϴ�. -----" << endl;
	for (int i = 0; i < idx; i++) {
		if (debug[i][0] == tag) {
			cout << debug[i][0] << ':' << debug[i][1] << endl;
		}
	}
}

void Trace::print() {
	cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
	for (int i = 0; i < idx; i++) {
		cout << debug[i][0] << ':' << debug[i][1] << endl;
	}
}


void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ��� >> ";
	cin >> a >> b;
	Trace::put("f()", "������ �Է¹޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

int main(void) {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");
	Trace::print("f()");
	Trace::print();
}