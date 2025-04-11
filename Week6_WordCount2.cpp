#include <iostream>
#include "Week6_WordCount2.h"
using namespace std;

WordCnt::WordCnt(string word, int cnt) {
	this->word = word;
	this->cnt = cnt;
}

string WordCnt::getWord() { return word; }
void WordCnt::increase() { cnt++; }
void WordCnt::show() {
	cout << word << ":" << cnt << endl;
}
