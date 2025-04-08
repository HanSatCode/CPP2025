#pragma once

class Exp {
	int base;
	int exp;
public:
	Exp(int a, int b);
	Exp(int a);
	Exp();

	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};