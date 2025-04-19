#include <stdio.h>
int main(void) {
	int w, h;
	printf("길이와 넓이 = ");
	scanf("%d %d", &h, &w);
	printf("둘레 = %d", (2 * w) + (2 * h));
}