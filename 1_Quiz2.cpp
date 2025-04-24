#include <stdio.h>
int main(void) {
	int x = 0;
	printf("x = ");
	scanf("%d", &x);
	printf("y = %d", (2 * x * x) + (3 * x) + 5);
}