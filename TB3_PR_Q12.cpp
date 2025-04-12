#include <iostream>
#include "TB3_PR_Q12.h"
using namespace std;

Ram::Ram() {
	for (int i = 0; i < 100 * 1024; i++) {
		mem[i] = 0;
	}
	size = 100 * 1024;
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

void Ram::write(int address, char value) {
	mem[address] = value;
}

char Ram::read(int address) {
	return mem[address];
}