#include <iostream>
using namespace std;

class Matrix {
	int w, x, y, z;
public:
	Matrix(int w = 0, int x = 0, int y = 0, int z = 0) {
		this->w = w; this->x = x; this->y = y; this->z = z;
	}
	void show() {
		cout << "Matrix = { " << w << ' ' << x << ' ' << y << ' ' << z << " }" << endl;
	}
	/*
	Matrix operator+(Matrix b) {
		Matrix temp;
		temp.w = this->w + b.w; temp.x = this->x + b.x;
		temp.y = this->y + b.y; temp.z = this->z + b.z;
		return temp;
	}

	Matrix& operator+=(Matrix& b) {
		this->w += b.w; this->x += b.x;
		this->y += b.y; this->z += b.z;
		return *this;
	}
	bool operator==(Matrix b) {
		if (this->w == b.w && this->x == b.x && this->y == b.y && this->z == b.z) return true;
		else return false;
	}
	*/
	friend Matrix operator+(Matrix op1, Matrix op2);
	friend Matrix& operator+=(Matrix &op1, Matrix op2);
	friend bool operator==(Matrix op1, Matrix op2);
};

Matrix operator+(Matrix op1, Matrix op2) {
	Matrix temp;
	temp.w = op1.w + op2.w; temp.x = op1.x + op2.x;
	temp.y = op1.y + op2.y; temp.z = op1.z + op2.z;
	return temp;
}

Matrix& operator+=(Matrix &op1, Matrix op2) {
	op1.w += op2.w; op1.x += op2.x;
	op1.y += op2.y; op1.z += op2.z;
	return op1;
}

bool operator==(Matrix op1, Matrix op2) {
	if (op1.w == op2.w && op1.x == op2.x && op1.y == op2.y && op1.z == op2.z) return true;
	else return false;
}

int main(void) {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}