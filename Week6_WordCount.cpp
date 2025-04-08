#include <iostream>
#include <string>
using namespace std;

/*
WordCount - ex. "I like C++ I like python" -> I : 2 / like : 2 / C++ : 1 / python : 1

1. �ܾ ���������� �ϳ��� ��������.
2. WordCnt Ŭ������ �̸� Ȱ���� ��ü�迭 ����
3. ī���� �˰���
	- �ܾ� ��������. ���� �ܾ �迭�� �����ϸ�, �迭 �� �ܾ��� cnt�� ����.
	- �׷���, ���࿡ �ܾ �迭�� �������� ������, �迭�� ���ο� �ܾ �߰�.
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
			return i; // �ε��� ��ȣ�� ��ȯ��
		}
	}
	return -1;
}

int main(void) {
	WordCnt *w[100]; // ���� �迭
	int wcnt = 0; // index + 1
	
	string temp;
	cout << "������ �Է����ּ���. >> ";
	getline(cin, temp, '\n');
	
	int startIndex = 0;
	int findIndex = 0;
	while (true) {
		findIndex = temp.find(' ', startIndex);
		if (findIndex == -1) {
			string word = temp.substr(startIndex);

			int ex = existWord(w, wcnt, word);
			if (ex != -1) { // ���࿡, �ܾ w�� ���縦 �Ѵٸ�?
				w[ex]->cnt += 1;
			}
			else { // �׷��� �ʰ�, �ܾ w�� ���縦 ���� �ʴ´ٸ�?
				w[wcnt] = new WordCnt(word, 1);
				wcnt++;
			}
			break;
		}
		int len = findIndex - startIndex;
		string word = temp.substr(startIndex, len);

		int ex = existWord(w, wcnt, word);
		if (ex != -1) { // ���࿡, �ܾ w�� ���縦 �Ѵٸ�?
			w[ex]->cnt += 1;
		}
		else { // �׷��� �ʰ�, �ܾ w�� ���縦 ���� �ʴ´ٸ�?
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