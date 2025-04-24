#include <iostream>
#include <string>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Date(string ymd) {
		int startIndex = 0;
		int result[3];
		for(int i = 0; i < 3; i++) {
			int findIndex = ymd.find('/', startIndex);
			result[i] = stoi(ymd.substr(startIndex, findIndex - startIndex));
			startIndex = ++findIndex;
		}
		this->year = result[0]; this->month = result[1]; this->day = result[2];
	}
	void show() {
		cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
	}
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

int main(void) {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}