#include <iostream>
using namespace std;

int main(void){
	// 1. 객채 내 데이터에 대한 외부에서의 접근을 제한하여 보호하기 위함
	// 2. 3번
	// 3. 캡슐화가 아니다. 정수형 변수 acc와 add 함수는 어떤 클래스에도 담겨있지 않다.
	// 4.
	class human {
		int age;
		void older() { age++; }
	};
	class Circle {
		int radius;
	public:
		double getArea();
	};
	// 5.
	class Circle {
		int radius;
		double getArea();
	};
	// 6.
	class Tower {
		int height = 20;
	public:
		Tower() { height = 10; }
	};
	// 7.
	class Building {
		int floor;
	public:
		Building() { floor = 1; }
		Building(int s) { floor = s; }
	};
	/*
	int main() {
		Buliding twin, star;
		Building BlueHouse(5), Jangmi(14);
	}
	*/
	//8.
	class Calendar {
	private:
		int year;
	public:
		Calendar() {
			year = 10;
		};
		int getYear();
	};
	// 9. 2번
	// 10. 3번
	// 12. c-b-a-a-b-c
	// 15. TV(), TV(int a)
	// 16. 2번
	// 17. 1번
	// 18. 1번
	// 19. 4번
}