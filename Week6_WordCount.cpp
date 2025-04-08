#include <iostream>
#include <string>
using namespace std;

/*
WordCount - ex. "I like C++ I like python" -> I : 2 / like : 2 / C++ : 1 / python : 1

1. 단어를 순차적으로 하나씩 가져오기.
2. WordCnt 클래스와 이를 활용할 객체배열 정의
3. 카운팅 알고리즘
	- 단어 가져오기. 만약 단어가 배열에 존재하면, 배열 속 단어의 cnt를 증가.
	- 그러나, 만약에 단어가 배열에 존재하지 않으면, 배열에 새로운 단어를 추가.
*/

class WordCnt {
public:
	string word;
	int cnt;
	WordCnt(string word, int cnt) {
		this->word = word;
		this->cnt = cnt;
	};
};

int existWord(WordCnt* list[], int size, string word) {
	for (int i = 0; i < size; i++) {
		if (list[i]->word == word) {
			return i; // 인덱스 번호를 반환함
		}
	}
	return -1;
}

int main(void) {
	WordCnt *w[100]; // 동적 배열
	int wcnt = 0; // index + 1
	
	string temp;
	cout << "문장을 입력해주세요. >> ";
	getline(cin, temp, '\n');
	
	int startIndex = 0;
	int findIndex = 0;
	while (true) {
		findIndex = temp.find(' ', startIndex);
		if (findIndex == -1) {
			string word = temp.substr(startIndex);

			int ex = existWord(w, wcnt, word);
			if (ex != -1) { // 만약에, 단어가 w에 존재를 한다면?
				w[ex]->cnt += 1;
			}
			else { // 그렇지 않고, 단어가 w에 존재를 하지 않는다면?
				w[wcnt] = new WordCnt(word, 1);
				wcnt++;
			}
			break;
		}
		int len = findIndex - startIndex;
		string word = temp.substr(startIndex, len);

		int ex = existWord(w, wcnt, word);
		if (ex != -1) { // 만약에, 단어가 w에 존재를 한다면?
			w[ex]->cnt += 1;
		}
		else { // 그렇지 않고, 단어가 w에 존재를 하지 않는다면?
			w[wcnt] = new WordCnt(word, 1);
			wcnt++;
		}
		startIndex = findIndex + 1;
	}
	cout << "index\t\tword\t\tcnt" << endl;
	for (int i = 0; i < wcnt; i++) {
		cout << i << "\t\t" << w[i]->word << "\t\t" << w[i]->cnt << endl;
	}
}