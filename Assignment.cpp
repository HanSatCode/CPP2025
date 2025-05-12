#include <iostream>
using namespace std;

class Rational {
	int child;
	int parent;
public:
	Rational(int child = 1, int parent = 1);

	void show() {
		cout << child << '/' << parent << endl;
	}

	Rational operator+ (Rational op2);
	Rational operator- (Rational op2);
	Rational operator/ (Rational op2);
	Rational operator* (Rational op2);
	friend Rational operator+ (int op1, Rational op2);
	Rational operator+ (int op2);
	Rational operator++ (int x);
	Rational& operator+= (Rational op2);
};

//------------------------------------------------------------------------

// 기약분수를 만드는 전역 함수
void giyak(int& child, int& parent) {
	int remainder = -1;
	int pre_child = child; int pre_parent = parent;
	if (pre_child == pre_parent) child = parent = 1; // 분모와 분자가 같은 경우
	else {
		if (pre_parent % pre_child == 0) remainder = child; // 바로 판단 가능할 경우 (1)
		else if (pre_child % pre_parent == 0) remainder = parent; // 바로 판단 가능할 경우 (2)
		else {
			if (child < parent) { // 분모가 분자보다 큰 경우
				while (true) {
					if (pre_parent % pre_child == 0) break;
					remainder = pre_parent % pre_child;
					pre_parent = pre_child;
					pre_child = remainder;
				}
			}
			else { // 분모가 분자보다 작은 경우
				while (true) {
					if (pre_child % pre_parent == 0) break;
					remainder = pre_child % pre_parent;
					pre_child = pre_parent;
					pre_parent = remainder;
				}
			}
		}
		child /= remainder; parent /= remainder;
	}
}

// 생성자
Rational::Rational(int child, int parent) {
	this->child = child;
	this->parent = parent;
	giyak(this->child, this->parent);
}

// result1 = a + b
Rational Rational::operator+ (Rational op2) {
	Rational temp;
	temp.child = (this->child * op2.parent) + (op2.child * this->parent);
	temp.parent *= this->parent * op2.parent;
	giyak(temp.child, temp.parent);
	return temp;
}

// result2 = a - b
Rational Rational::operator- (Rational op2) {
	Rational temp;
	temp.child = (this->child * op2.parent) - (op2.child * this->parent);
	temp.parent *= this->parent * op2.parent;
	giyak(temp.child, temp.parent);
	return temp;
}

// result3 = a / b
Rational Rational::operator/ (Rational op2) {
	Rational temp;
	temp.child = this->child * op2.parent;
	temp.parent *= this->parent * op2.child;
	giyak(temp.child, temp.parent);
	return temp;
}

// result4 = a * b
Rational Rational::operator* (Rational op2) {
	Rational temp;
	temp.child = this->child * op2.child;
	temp.parent *= this->parent * op2.parent;
	giyak(temp.child, temp.parent);
	return temp;
}

// result5 = 2 + a
Rational operator+ (int op1, Rational op2) {
	Rational temp;
	temp.child = op2.child + (op1 * op2.parent);
	temp.parent = op2.parent;
	giyak(temp.child, temp.parent);
	return temp;
}

// result5 = a + 2
Rational Rational::operator+ (int op2) {
	Rational temp;
	temp.child = this->child + (op2 * this->parent);
	temp.parent = this->parent;
	giyak(temp.child, temp.parent);
	return temp;
}

// reuslt6 = a++;
Rational Rational::operator++ (int x) {
	Rational temp = *this; //현 상태를 저장함 
	this->child = this->child + (this->parent);
	giyak(this->child, this->parent);
	return temp;
}

// a += b;
Rational& Rational::operator+= (Rational op2) {
	this->child = (this->child * op2.parent) + (op2.child * this->parent);
	this->parent = this->parent * op2.parent;
	giyak(this->child, this->parent);
	return *this;
}

//------------------------------------------------------------------------

int main(void) {
	Rational a(2, 3), b(4, 5);
	Rational result1, result2, result3, result4, result5, result6;

	a.show(); b.show();

	cout << "*-*-*-*-* 사칙연산 입니다. *-*-*-*-*" << endl;
	result1 = a + b; result2 = a - b; result3 = a / b; result4 = a * b;
	result1.show(); result2.show(); result3.show(); result4.show();

	cout << "*-*-*-*-* 정수 2 더하기 입니다. *-*-*-*-*" << endl;
	result5 = 2 + a; result5.show(); // 서로 같은 값을 가질 경우 정상
	result5 = a + 2; result5.show(); // 서로 같은 값을 가질 경우 정상

	cout << "*-*-*-*-* 후위 연산자 입니다. *-*-*-*-*" << endl;
	result6 = a++;
	result6.show(); a.show(); // 서로 다른 값을 가질 경우 정상

	cout << "*-*-*-*-* 객체 값 누적 입니다. *-*-*-*-*" << endl;
	a.show(); b.show();
	a += b; a.show();
}