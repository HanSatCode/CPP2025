#include <iostream>
using namespace std;

// (3) ���� ���� : b, c, a, d / �Ҹ� ���� : a, d, c, b / ���� : b-c-a-a-d-c-b

class House {
	int numOfRooms;
	int size;
public:
	~House();
	House(int n, int s);
};

House::House(int n, int s) {
	numOfRooms = n;
	size = s;
	cout << "�� ���� : " << numOfRooms << ", ������ : " << size << endl;
}

House::~House() {
	cout << "�� ���� : " << numOfRooms << ", ������ : " << size << endl;
}

void f() {
	House a(2, 20);
}
House b(3, 30), c(4, 40);
int main(void) {
	f();
	House d(5, 50);
}