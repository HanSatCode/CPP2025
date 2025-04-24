#include <iostream>
using namespace std;

class TV {
public:
	int channels;
	TV() { channels = 256; }
	TV(int a) { channels = a; }
};

int main(void) {
	TV LG;
	LG.channels = 200;
	TV Samsung(100);
}