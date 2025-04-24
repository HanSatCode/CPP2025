#include <iostream>
using namespace std;

// (3) 생성 순서 : b, c, a, d / 소멸 순서 : a, d, c, b / 종합 : b-c-a-a-d-c-b

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
	cout << "방 갯수 : " << numOfRooms << ", 사이즈 : " << size << endl;
}

House::~House() {
	cout << "방 갯수 : " << numOfRooms << ", 사이즈 : " << size << endl;
}

void f() {
	House a(2, 20);
}
House b(3, 30), c(4, 40);
int main(void) {
	f();
	House d(5, 50);
}