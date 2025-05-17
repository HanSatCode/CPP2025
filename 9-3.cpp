#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};

class GrandDerived : public Derived {
public:
	virtual void f() { cout << "GrandDeriveed::F() called" << endl; }
};

int main(void) {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;

	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}