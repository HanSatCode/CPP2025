#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string song("Falling in love with you"); // ���ڿ� song
	string elvis("Elvis Presley"); // ���ڿ� elvis
	string singer; // ���ڿ� singer

	cout << song + "�� �θ� ������"; // + �� ���ڿ� ����
	cout << "(��Ʈ: ù���ڴ� " << elvis[0] << ")? "; // [] ������ ���
	
	getline(cin, singer); // getline������ �����ؼ� �Է��� �����ϴ�. �� �� �Է��� �޴´�.
	if (singer == elvis) {
		cout << "�¾ҽ��ϴ�.";
	}
	else {
		cout << "Ʋ�Ƚ��ϴ�. " + elvis + " �Դϴ�." << endl;
	}
}