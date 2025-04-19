#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n / 100 == 12) printf("오후 12시 %d분", (n % 100));
	else if (n / 100 == 0) printf("오전 12시 %d분", (n % 100));
	else if (n / 100 < 12) printf("오전 %d시 %d분", n / 100, n % 100);
	else printf("오후 %d시 %d분", (n / 100) - 12, n % 100);
}