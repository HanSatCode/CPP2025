#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::~Person() {
	if (name) {
		delete[] name;
	}
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) {
		return;
	}
	strcpy(this->name, name);
}

int main(void) {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter 객체 생성 직후 -----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경 후 -----" << endl;
	father.show();
	daughter.show();

	return 0;
}