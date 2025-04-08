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
		int findIndex = 0;
		bool first = true;
		while (true) {
			findIndex = ymd.find('/', startIndex);
			if (findIndex == -1) {
				this->day = stoi(ymd.substr(startIndex));
				break;
			}
			int len = findIndex - startIndex;
			if (first) {
				this->year = stoi(ymd.substr(startIndex, len));
				first = false;
			}
			else {
				this->month = stoi(ymd.substr(startIndex, len));
			}
			startIndex = findIndex + 1;
		}
	}
	void show() {
		cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
	}

	int getYear() {
		return year;
	}

	int getMonth() {
		return month;
	}

	int getDay() {
		return day;
	}
};

int main(void) {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}