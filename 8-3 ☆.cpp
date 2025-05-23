#include <iostream>
#include <string>
using namespace std;

class TV {
	int size; // 스크린 크기
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV : public TV { // TV를 상속받는 WideTV
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) : WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};

int main(void) {
	SmartTV htv("192.0.0.1", 32);
	cout << "size = " << htv.getSize() << endl;
	cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
	cout << "IP = " << htv.getIpAddr() << endl;
}