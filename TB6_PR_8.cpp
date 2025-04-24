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
	cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < idx; i++) {
		if (debug[i][0] == tag) {
			cout << debug[i][0] << ':' << debug[i][1] << endl;
		}
	}
}

void Trace::print() {
	cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < idx; i++) {
		cout << debug[i][0] << ':' << debug[i][1] << endl;
	}
}


void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요 >> ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main(void) {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();
}