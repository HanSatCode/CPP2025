#include <iostream>
using namespace std;

class Tower {
	int meter;
public:
	Tower() { meter = 1; }
	Tower(int m) { meter = m; }

	int getHeight() {
		return meter;
	}
};

int main(void) {
	Tower myTower;
	Tower seoulTower(100);
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}