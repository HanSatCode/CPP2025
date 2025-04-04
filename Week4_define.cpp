#include <stdio.h>

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mul(int x, int y) {
	return x * y;
}

int  div(int x, int y) {
	return x / y;
}

int main(void) {
	int a = 0;
	int b = 0;
	printf("a와 b를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	
	//---------------------
	
	printf("%d + %d = %d\n", a, b, sum(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d * %d = %d\n", a, b, mul(a, b));
	printf("%d / %d = %d\n", a, b, div(a, b));

	return 0;
}