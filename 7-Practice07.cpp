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
	void operator>>(int op[]) {
		op[0] = this->w; op[1] = this->x;
		op[2] = this->y; op[3] = this->z;
	}
	Matrix operator<<(int op[]) {
		Matrix temp;
		this->w = op[0]; this->x = op[1];
		this->y = op[2]; this->z = op[3];
		return temp;
	}
	*/
	friend void operator>>(Matrix op1, int op2[]);
	friend void operator<<(Matrix& op1, int op2[]);
};

void operator>>(Matrix op1, int op2[]) {
	op2[0] = op1.w; op2[1] = op1.x;
	op2[2] = op1.y; op2[3] = op1.z;
}

void operator<<(Matrix &op1, int op2[]) {
	op1.w = op2[0]; op1.x = op2[1];
	op1.y = op2[2]; op1.z = op2[3];
}

int main(void) {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}