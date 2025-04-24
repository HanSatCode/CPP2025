#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(int r = 100) { this->radius = r; }
};

int main(void) {
	Circle a[10];
	cout << a[0].radius << endl;
}