#include <iostream>
using namespace std;

class TV {
	bool on = false;
	int channel = 10;
	int volume = 0;
public:
	void powerOn() {
		on = true;
	}
	void powerOff() {
		on = false;
	}
	void increaseChannel() {
		if (on) {
			if (channel < 99) {
				channel++;
			}
			else {
				channel = 1;
			}
		}
	}
};

int main(void) {
	TV t1, t2;
	t1.powerOn();
	t1.increaseChannel();
	return 0;
}