#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
public:
	int r;
	Circle(int r) { this->r = r; }
	bool operator<(Circle b);
	bool operator>(Circle b);
};

bool Circle::operator<(Circle op) {
	return this->r > op.r;
}

bool Circle::operator>(Circle op) {
	return this->r > op.r;
}

int main(void) {
	vector<Circle> circle_v;
	Circle c[] = { Circle(4), Circle(2), Circle(10), Circle(5) };

	for (int i = 0; i < 4; i++) {
		circle_v.push_back(c[i]);
	}

	sort(circle_v.begin(), circle_v.end(), [](Circle a, Circle b) { return a > b; });

	for (auto circle : circle_v) {
		cout << circle.r << " ";
	}
	cout << endl;
}