#include <iostream>
using namespace std;

class TV {
public:
	int channels;
	int colors;
	TV() { channels = 256; }
	TV(int a, int b) { channels = a; colors = b; }
};

int main() {
	TV LG;
	LG.channels = 200;
	LG.colors = 60000;
	TV Samsung(100, 50000);
}