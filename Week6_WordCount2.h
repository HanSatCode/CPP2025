#pragma once
#include <iostream>
using namespace std;

class WordCnt {
	string word;
	int cnt;
public:
	WordCnt(string word, int cnt);
	void increase();
	string getWord();
	void show();
};