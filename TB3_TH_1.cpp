#include <iostream>
using namespace std;

int main(void){
	// 1. ��ä �� �����Ϳ� ���� �ܺο����� ������ �����Ͽ� ��ȣ�ϱ� ����
	// 2. 3��
	// 3. ĸ��ȭ�� �ƴϴ�. ������ ���� acc�� add �Լ��� � Ŭ�������� ������� �ʴ�.
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
	// 9. 2��
	// 10. 3��
	// 12. c-b-a-a-b-c
	// 15. TV(), TV(int a)
	// 16. 2��
	// 17. 1��
	// 18. 1��
	// 19. 4��
}