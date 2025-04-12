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
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}