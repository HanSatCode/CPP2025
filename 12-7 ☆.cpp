#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// 소스 파일과 목적 파일의 이름
	const char* srcFile = "src\\Test.jpg";
	const char* destFile = "src\\TestCopy.jpg";
	
	// 소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cerr << "소스 파일을 열 수 없습니다: " << srcFile << endl;
		return 1;
	}
	
	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cerr << "목적 파일을 열 수 없습니다: " << destFile << endl;
		fsrc.close();
		return 1;
	}

	// 소스 파일에서 목적 파일로 복사하기
	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "을 " << destFile << "로 복사했습니다." << endl;
	fsrc.close();
	fdest.close();
}