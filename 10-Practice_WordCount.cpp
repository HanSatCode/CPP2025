#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	string temp; cout << "문자열을 입력해주세요. >> "; getline(cin, temp, '\n');

	map<string, int> dict;
	map<string, int>::iterator it;
	int startIndex = 0;
	int findIndex = 0;

	int len;
	string word;
	while (true) {
		findIndex = temp.find(' ', startIndex);
		
		if (findIndex == -1) { // 마지막 단어
			word = temp.substr(startIndex);
			if (dict.find(word) == dict.end()) dict[word] = 1;
			else dict[word] += 1;
			break;
		}
		len = findIndex - startIndex;
		word = temp.substr(startIndex, len);
		if (dict.find(word) == dict.end()) dict[word] = 1;
		else dict[word] += 1;
		startIndex = findIndex + 1;
	}

	int idx = 1;
	for (it = dict.begin(); it != dict.end(); it++) {
		cout << "[" << idx++ << "] " << it->first << " : " << it->second << endl;
	}
	
}