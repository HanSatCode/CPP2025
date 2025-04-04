#include <stdio.h>

void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b) {
	int temp = *a; // temp에 a가 가리키는 값을 저장한다.
	*a = *b; // a가 가리키는 곳에 b가 가리키는 값을 저장한다.
	*b = temp; // b가 가르키는 곳에 temp 값을 저장한다.
}

int main(void) {
	int x = 10, y = 20;
	printf("x = %d, y = %d\n", x, y);
	swap1(x, y);
	printf("swap1() 호출 후 x = %d, y = %d\n", x, y);
	swap2(&x, &y);
	printf("swap2() 호출 후 x = %d, y = %d\n", x, y);
}