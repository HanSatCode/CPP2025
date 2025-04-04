#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string song("Falling in love with you"); // 문자열 song
	string elvis("Elvis Presley"); // 문자열 elvis
	string singer; // 문자열 singer

	cout << song + "를 부른 가수는"; // + 로 문자열 연결
	cout << "(힌트: 첫글자는 " << elvis[0] << ")? "; // [] 연산자 사용
	
	getline(cin, singer); // getline공백을 포함해서 입력이 가능하다. 한 줄 입력을 받는다.
	if (singer == elvis) {
		cout << "맞았습니다.";
	}
	else {
		cout << "틀렸습니다. " + elvis + " 입니다." << endl;
	}
}