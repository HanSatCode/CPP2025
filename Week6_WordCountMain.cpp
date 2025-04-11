#include <iostream>
#include <string>
#include "Week6_WordCount2.h"
using namespace std;

int findWordIndex(WordCnt* w[], int cnt, string element) {
	for (int i = 0; i < cnt; i++) {
		if (w[i]->getWord() == element) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	int cnt = 0;
	string question;
	WordCnt* w[100]; // WordCnt 타입의 포인터 배열을 만듦 (만든거 자체는 아무것도 가리키고 있지 않음)
	getline(cin, question, '\n');

	int startIndex = 0;
	int findIndex = 0;
	while (true) {
		findIndex = question.find(' ', startIndex);
		if (findIndex == -1) {
			string element = question.substr(startIndex);
			int wordIndex = findWordIndex(w, cnt, element);

			if (wordIndex == -1) { // 만약에 원소가 없는 경우?
				w[cnt] = new WordCnt(element, 1);
				cnt++;
			}
			else w[wordIndex]->increase(); // 만약에 원소가 있는 경우
			break;
		}
		int len = findIndex - startIndex;
		string element = question.substr(startIndex, len);
		
		int wordIndex = findWordIndex(w, cnt, element);

		if (wordIndex == -1) { //만약에 원소가 없는경우
			w[cnt] = new WordCnt(element, 1);
			cnt++;
		}
		else w[wordIndex]->increase(); // 만약에 원소가 있는 경우
		startIndex = findIndex + 1;
	}

	for (int i = 0; i < cnt; i++) {
		w[i]->show();
	}
}