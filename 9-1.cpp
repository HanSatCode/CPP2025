#include <iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

int main(void) {
	Derived d, *pDer;
	pDer = &d;
	pDer->f(); //Deriverd::f() ȣ��

	Base* pBase;
	pBase = pDer;
	pBase->f(); //Base::f() ȣ��

}