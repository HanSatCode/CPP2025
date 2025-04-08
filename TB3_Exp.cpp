#include <iostream>
#include "Exp.h"
using namespace std;

Exp::Exp(int a, int b) {
	this->base = a;
	this->exp = b;
}

Exp::Exp(int a) {
	this->base = a;
	this->exp = 1;
}

Exp::Exp() {
	this->base = 1;
	this->exp = 1;
}
int Exp::getValue() {
	int result = this->base;
	for (int i = 0; i < this->exp - 1; i++) {
		result *= base;
	}
	return result;
}

int Exp::getBase() {
	return base;
}

int Exp::getExp() {
	return exp;
}

bool Exp::equals(Exp b) {
	if (b.getValue() == this->getValue()) {
		return true;
	}
	return false;
}