#include <iostream>
using namespace std;

int main(void) {
	cout << "너비를 입력하세요 >> ";

	int width;
	cin >> width; // 키보드로부터 너비를 읽어 width 변수에 저장

	cout << "높이를 입력하세요 >> ";

	int height;
	cin >> height;

	int area = width * height;
	cout << "면적은 " << area << endl;
}