#include <stdio.h>

void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b) {
	int temp = *a; // temp�� a�� ����Ű�� ���� �����Ѵ�.
	*a = *b; // a�� ����Ű�� ���� b�� ����Ű�� ���� �����Ѵ�.
	*b = temp; // b�� ����Ű�� ���� temp ���� �����Ѵ�.
}

int main(void) {
	int x = 10, y = 20;
	printf("x = %d, y = %d\n", x, y);
	swap1(x, y);
	printf("swap1() ȣ�� �� x = %d, y = %d\n", x, y);
	swap2(&x, &y);
	printf("swap2() ȣ�� �� x = %d, y = %d\n", x, y);
}